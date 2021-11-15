public class Average_Speed {
    public static void main(String[] args) {
    System.out.println("kph: " + mphToKph(milesPerHour(24, 100.58)));
  }

  private static double milesPerHour(double miles, double minutes) {
    return 60.0 * (miles / minutes);
  }

  private static double mphToKph(double mph) {
    return mph * 1.6;
  }
}
