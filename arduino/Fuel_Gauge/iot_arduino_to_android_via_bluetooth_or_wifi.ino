#include <SoftwareSerial.h>
SoftwareSerial btserial(0,1);
#define RX 2
#define TX 3

//Code to send sensor values to the Android App via Wifi/Bluetooth
//The code send values via Wifi (Priority 1)
//If Wifi offline, then send values via BT (Priority 2)

String AP = "JIOaryan";       // AP NAME
String PASS = "papiya123"; // AP PASSWORD
String API = "HIF8U33OAGKYTWPF";   // Write API KEY
String HOST = "api.thingspeak.com";
String PORT = "80";
String field = "field1";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
SoftwareSerial esp8266(RX,TX); 
int trigger_pin = 11; //ultrasonic sensor

int echo_pin = 10; //ultrasonic sensor

int time;

int distance; 


//assuming the tank to be cylindrical

float height = 40; //height of the tank

//float radius = 10 //radius of the tank
  
void setup() {
  Serial.begin(9600);
btserial.begin(9600);
  esp8266.begin(115200);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
   pinMode (trigger_pin, OUTPUT); 

   pinMode (echo_pin, INPUT);

   pinMode (9, OUTPUT);
}

void loop() {
 valSensor = getSensorData();
 String getData = "GET /update?api_key="+ API +"&"+ field +"="+String(valSensor);
sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.println(getData);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
}

int getSensorData(){
  digitalWrite (trigger_pin, HIGH);

    delay(100);

    digitalWrite (trigger_pin, LOW);

    time = pulseIn (echo_pin, HIGH);

    distance = (time * 0.034) / 2;
if(distance>height)
{
  return 100; //fuel in percentage
  Serial.println(100);
}
else
{
return (((height-distance)/height)*100); //fuell in percentage
 Serial.println(((height-distance)/height)*100);
}
//  return random(1000); 
}

void sendCommand(String command, int maxTime, char readReplay[]) {
//  Serial.print(countTrueCommand);
//  Serial.print(". at command => ");
//  Serial.print(command);
//  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
//    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
//    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }
