#include <SoftwareSerial.h>
#include<SD.h>
#include <Servo.h> 
#include<SPI.h>
#include<Wire.h>
#include<OneWire.h>
#include<DallasTemperature.h>

Servo servo;
int angle = 0;

/*Parameters associated with TDS(Total Dissolved Solid)*/ 

int R1= 2200;
int Ra=25; //Resistance of powering Pins
int ECPin= A0;
float PPMconversion=0.7;
float TemperatureCoef = 0.019; 
float K=2.88;
float EC=0;
float EC25 =0;
int TDS_ppm =0;
float raw= 0;
float Vin= 5;
float Vdrop;
float Rc= 0;
float buffer=0;

// Parameters associated to Nitrogen Sensor 

#define PRE_PIN  8
#define VNOX_PIN A12
#define PRE_HEAT_SECONDS 10

int vnox_value;
float vnox_r0 = 0.91;
float vnox_volt;
float vnox_rsgas;
float vnox_ratio;
float vnox_ppm;

int tpin = 2;//One wire temperature sensor digital pin

int tubpin = A13;//Turbidity Sensor pin

float t;// Temperature Variable
float tub;// Turbidity computing variable
float ntu;

#define rxPin 4                  // Recieve Pin on HC12
#define txPin 5                  // Transmit Pin on HC12


OneWire T(tpin);
DallasTemperature tsensor(&T);

#define SensorPin A1 //pH meter Analog output to Arduino Analog Input 0
#define Offset 0.00 //deviation compensate
#define samplingInterval 20
#define printInterval 800
int buf[80];
int pH; //Store the average value of the sensor feedback
static float pHValue,voltage;
float avg;
#define samplingInterval 20

SoftwareSerial HC12(rxPin, txPin); 

void setup()
{
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 servo.attach(9);
 HC12.begin(115200);
 Serial.begin(115200);
 pinMode(PRE_PIN, OUTPUT);
 pinMode(ECPin,INPUT);
 R1=(R1+Ra);
 digitalWrite(PRE_PIN, 1);
 delay(PRE_HEAT_SECONDS * 1000);
 digitalWrite(PRE_PIN, 0);
 tsensor.begin();
 vnox_value = analogRead(VNOX_PIN);
 vnox_volt = ((float)vnox_value/1024.0)*5.0;
 vnox_rsgas = (5.0 - vnox_volt)/vnox_volt;
 vnox_ratio = vnox_rsgas/vnox_r0; 
 vnox_ppm = pow(0.0000000000000000084,vnox_ratio)*1000;
 if(vnox_ppm>0)
   {
    if(vnox_ppm<0.5){}
    if(vnox_ppm>0.5){vnox_ppm = 0.22;}
   }
 HC12.write("AT+DEFAULT");
 while (HC12.available() > 0){Serial.write(HC12.read());}
}
float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}

boolean state = false;


void loop()
{
 for(int i=0;i<8;i++)
    {
     buf[i] = analogRead(SensorPin);
     delay(10); 
    }
  for(int i=0;i<7;i++)
     {
      for(int j=i+1;j<7;j++)
         {
          if(buf[i]>buf[j])
            {
             t = buf[i];
             buf[j]=buf[i];
             buf[j]=t; 
            }
         }
     }
 avg=0;
 for(int i=2;i<8;i++)
 {
  avg+=buf[i];
 }
 pHValue = (float)avg*5.0/1024/6;
 pHValue= 3.5*pHValue;
 static unsigned long samplingTime = millis();
 static unsigned long printTime = millis();
 tsensor.requestTemperatures();
 t = tsensor.getTempCByIndex(0);
 for(int i=0;i<800;i++)
 {
 tub = analogRead(tubpin);
 tub = ((5.0/1023.)*tub);
 }
 tub = round_to_dp(tub,1);
 tub = tub/800;
 if(tub < 2.5)
 {
  ntu = 3000;
 }
 else{ntu = -1120.4*pow(tub,2)+5742.3*tub-4353.8;}
 
 raw = analogRead(ECPin);
 Vdrop = (Vin*raw)/1024.0;
 Rc = (Vdrop*R1)/(Vin-Vdrop);
 Rc = Rc-Ra;
 EC = 1000/(Rc*K);
 EC25  =  EC/ (1+ TemperatureCoef*(t-25.0));
 TDS_ppm = (EC25)*(PPMconversion*1000);
 if(TDS_ppm<0){TDS_ppm = -TDS_ppm;}
 Serial.print(t);
 Serial.print(",");
 Serial.print(ntu);
 Serial.print(",");
 Serial.print(TDS_ppm);
 Serial.print(",");
 Serial.print(vnox_ppm);
 Serial.print(",");
 Serial.print(pHValue,2);
 Serial.println();
 if(ntu>200){servo.write(50);}
 delay(2000);
 HC12.println(t);                   // If Arduino's computer rx buffer has data// Send that data to serial
 state = not state;
}
