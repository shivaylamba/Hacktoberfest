import java.util.*;  

public class FascinatingNumber {  
  public static void main(String args[]) {  
    int num, n2, n3;      
    Scanner sc=new Scanner(System.in);  
    System.out.print("Enter any Number: ");  
    num = sc.nextInt();  
    n2 = num * 2;  
    n3 = num * 3;  
    //concatenating num, n2, and n3  
    String concatstr = num + "" + n2 + n3;  
    boolean found = true;  
    //checks all digits from 1 to 9 are present or not  
    for(char c = '1'; c <= '9'; c++) {  
      int count = 0;  
      //loop counts the frequency of each digit  
      for(int i = 0; i < concatstr.length(); i++) {  
        char ch = concatstr.charAt(i);  
        //compares the character of concatstr with i  
        if(ch == c)  
          //incerments the count by 1 if the specified condition returns true  
          count++;  
      }  
      //returns true if any of the condition returns true  
      if(count > 1 || count == 0)  
      {  
        found = false;  
        break;  
      }  
    }  
    if(found)  
      System.out.println(num + " is a fascinating number.");  
    else  
      System.out.println(num + " is not a fascinating number.");  
  }  
}
