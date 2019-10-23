import java.util.*;

public class OTP{
	
	public static void main(String[] args) {
		
		//Define sets of strings to be used in OTP generation
		String CAP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String LOW = "abcdefghijklmnopqrstuvwxyz";
		String NUM = "0123456789";
		String MIX = CAP + LOW + NUM;
		
		//New random randomized variable
		Random rand = new Random();
		
		//Storing variable
		char[] store = new char[19];
		
		for(int i=0; i<19;i++) {
			if(i<4) {
				store[i] = CAP.charAt(rand.nextInt(CAP.length()));
			}
			store[4] = '-';
			if(i>4 && i<9) {
				store[i] = NUM.charAt(rand.nextInt(NUM.length()));
			}
			store[9] = '-';
			if(i>9 && i<14) {
				store[i] = LOW.charAt(rand.nextInt(LOW.length()));
			}
			store[14] = '-';
			if(i>14) {
				store[i] = MIX.charAt(rand.nextInt(MIX.length()));
			}
		}
		System.out.println(store);
	}
}