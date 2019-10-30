import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class ArrayElementFrequency {

    // Complete the sockMerchant function below.
    static int sockMerchant(int n, int[] ar) {
        Arrays.sort(ar);
        int sum=0, count=0, as=0;
        for(int i=0;i<n;i+=count){
            int x=ar[i];
			count=0;
            for(int j=i;j<n;j++){
                if(x==ar[j])
                count++;
            }
			sum+=(count/2);
			if(count==0)
				count++;
				
			System.out.println(x+" : Occurs "+count+" times!");
		}
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[] ar = new int[n];

        String[] arItems = br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = sockMerchant(n, ar);
		System.out.println("Total Pairs: "+result);
		
		br.close();
    }
}