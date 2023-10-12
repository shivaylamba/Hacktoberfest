public class Factorial {

    public long factorial(int N) {
        long result = 1;
        for(long i = 2; i <= N ; i++){
            result = result * i;
        }
        
        return result;
    }

   public static void main(String args[]) {
      Factorial getFactorial = new Factorial();
      long fact = getFactorial.factorial(20);
      System.out.println(fact);
    }
}
