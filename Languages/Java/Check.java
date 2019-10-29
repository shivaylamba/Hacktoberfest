import java.util.*;
class Check
{
    void check(String str, char ch)
    {
        int count=0;
        for(int i=0; i<str.length();i++)
        {
            if(str.charAt(i)==ch)
                count++;
        }
        System.out.println("number of "+ch+" present is="+count);
    }

    void check (String s1)
    {
        s1=s1.toLowerCase();
        for(int i=0;i<s1.length();i++)
        {
            char ch = s1.charAt(i);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                System.out.print(ch + " ");
        }

    }  
}