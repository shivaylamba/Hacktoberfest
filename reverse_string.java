import java.util.Scanner;  
class ReverseString  
{  
public static void main(String args[])  
{  
String s;  
Scanner sc=new Scanner(System.in);                   
System.out.print("Enter a String: ");  
s=sc.nextLine();  
System.out.print("After reverse string is: ");  
int i=s.length();                  
while(i>0)  
{  
System.out.print(s.charAt(i-1));                 
i--;                               
}  
}  
}
