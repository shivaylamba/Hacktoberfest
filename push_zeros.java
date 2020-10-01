import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class push_zeros
{
    public static void main(String[] args) {
//        Scanner s=new Scanner(System.in);
//        System.out.println("Enter the length of the array");
//        int arr_length=s.nextInt();
//        int arr[]=new int[arr_length];int arr1[]=new int[arr_length];
//        for(int x=0;x<arr_length;x++)
//        {
//            arr[x]=s.nextInt();
//        }
//        int count1=0;
//          double ans=Double.parseDouble("12.");
//        System.out.println(ans);
//        ArrayList<Integer> ans=new ArrayList<Integer>();
//        System.out.println(ans.size());
//        ans.
//        HashMap<String,Integer> min=new HashMap<>();
//        String str="Sagar rergjnr rnoeraiof foiefoe efindnvoie fninefnoeinf ernfeo  ";
//        String arr[]=str.split(" ");
//        System.out.println(arr.length);
//        for(int x=0;x<arr.length;x++)
//        {
//            System.out.println(arr[x]);
//        }
//        for(int x=0;x<arr.length;x++)
//        {
//            if(arr[x]!=0)
//            {
//                arr1[count1]=arr[x];
//                count1++;
//            }
//        }
//        for(int x=arr1.length;x<arr.length;x++)
//        {
//            arr1[x]=0;
//        }
//        for(int x=0;x<arr.length;x++)
//        {
//            System.out.println(arr1[x]);
//        }
//        String display="48 + 87";
//        double num1=0;
//        String equation[]=display.split(" ");
//        for(int x=0;x<equation.length;x++)
//        {
//            System.out.println(equation[x]);
//        }
//        for(int x=0;x<equation.length;x++)
//        {
//            if(x==0){
//                num1 = Double.parseDouble(equation[x]);}
//            else if(equation[x].equals("+")){
//                num1=num1+Double.parseDouble(equation[x+1]);
//                System.out.println("Plus");}
//            else if(equation[x]=="-"){
//                num1=num1-Double.parseDouble(equation[x+1]);}
//            else if(equation[x]=="x"){
//                num1=num1*Double.parseDouble(equation[x+1]);}
//            else if(equation[x]=="%"){
//                num1=num1%Double.parseDouble(equation[x+1]);}
//            else if(equation[x]=="/"){
//                num1=num1/Double.parseDouble(equation[x+1]);}
//        }
//        System.out.println((int)num1);
//            num1=(int)num1;
//        System.out.println(num1);
//String h="(";
//char m=(char)h.charAt(0);
//        System.out.println();
        ArrayList<Integer> ans=new ArrayList<>();int count=0;ArrayList<Integer> input=new ArrayList<>();input.add(0,1);
        input.add(1,3);
        input.add(2,5);
        input.add(3,6);
        input.add(4,4);
        input.add(5,3);
        int sum=9;int help=0;
        for(int x=0;x<input.size()-1;x++)
        {

            for(int y=x+1;y<input.size();y++)
            {
                help=input.get(x)+input.get(y);
                if((input.get(x)+input.get(y))==sum)
                {
                    System.out.println(input.get(x));
                    System.out.println(input.get(y));
                    ans.add(0,input.get(x));
                    ans.add(1,input.get(y));
                    count++;
                    break;
                }
            }
            if(count!=0)
            {
                break;
            }
        }
    }
}
