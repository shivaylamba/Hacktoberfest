
import java.util.*;
public class Subsequence {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        subseq("",str);
    }

    public static void subseq(String proc, String unproc) {
        if(unproc.isEmpty()){
            System.out.println(proc);
            return;
        }

        char ch=unproc.charAt(0);
        unproc=unproc.substring(1);
        subseq(proc+ch,unproc);
        
        subseq(proc,unproc);
        


    }

}