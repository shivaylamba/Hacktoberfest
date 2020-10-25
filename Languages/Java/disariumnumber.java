import java.io.*;
class DisariumNumber
    {
    public static void main(String[] args)throws IOException
        {
            BufferedReader br=new BufferedReader (new InputStreamReader(System.in));
            System.out.print("Enter a number : ");
            int n = Integer.parseInt(br.readLine());
            int copy = n, d = 0, sum = 0;
            String s = Integer.toString(n); //converting the number into a String
            int len = s.length(); //finding the length of the number i.e. no.of digits
           
            while(copy>0)
            {
                d = copy % 10; //extracting the last digit
                sum = sum + (int)Math.pow(d,len);
                len--;
                copy = copy / 10;
            }
           
            if(sum == n)
                System.out.println(n+" is a Disarium Number.");
            else
                System.out.println(n+" is not a Disarium Number.");
        }
    }

