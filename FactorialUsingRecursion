import java.util.Scanner;
import java.lang.Math;
public class facr {
public static Scanner scn=new Scanner(System.in);
    public static void main(String[] Args){
int a,b;
a= scn.nextInt();
b= scn.nextInt();
System.out.println(opow(a,b));
}

public static int powe(int a,int b){
  if(b<=1){
      return a;   
  }
    int pw= powe(a,b-1);
    System.out.println(pw);
    return a*pw;
               
}
public static int opow(int a,int b){
    if(b==0){
        return 1;
    }
    int pw; //

    pw=opow(a,b/2);
 if(b%2==0){  
   return a*pw;}
   else{
       return a*a*pw;
   }

}
}
