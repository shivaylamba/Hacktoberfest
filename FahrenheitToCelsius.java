import java.util.*;
 
class FahrenheitToCelsius {
  public static void main(String[] args) {
    double temperature;
    Scanner in = new Scanner(System.in);
 
    System.out.println("Enter temperature in Fahrenheit");
    temperature = in.nextDouble();
 
    double temperature2 = ((temperature - 32)*5)/9;
 
    System.out.println("temperature in Celsius = " );
    System.out.printf("%2f" + temperature2);
  }
}
