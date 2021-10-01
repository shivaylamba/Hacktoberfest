import java.util.*;
class Q4
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input a String.");
        String s = sc.nextLine();
        s = s+" ";String W="";String NS="";//I know I could have used StringBuffers but this way it's FUN !! 
        int l = s.length();
        for(int x=0;x<l;x++)
        {
            char ch=s.charAt(x);
            if(ch!=' ')
              W = W+ch;
            if(ch==' ')
            {
                int wl=W.length();
                if((wl%2)==0)
                    W=W.toLowerCase();
                else
                {
                    int i=wl/2;
                    char arr[]=W.toCharArray();//took this measure to capitalise only the required letter.
                    arr[i]=Character.toUpperCase(arr[i]);
                    W=new String(arr);
                }
                NS=NS+W+" ";
                W="";
            }
            
        }
        System.out.println("Input : "+s);
        System.out.println("Output : "+NS);
    }
}
