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
        int sum=0, cnt=0, as=0;
        for(int i=0;i<n;i+=cnt){
            int x=ar[i];
			cnt=0;
            for(int j=i;j<n;j++){
                if(x==ar[j])
                cnt++;
            }
			sum+=(cnt/2);
			if(cnt==0)
				cnt++;
				
			System.out.println(x+" : Occurs "+cnt+" times!");
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