package com.company.Lec9;

public class Permutation {
    public static void perm(String pro,String un)
    {
        if(un.isEmpty())
        {
            System.out.println(pro);
            return;
        }

        char ch=un.charAt(0);
        un=un.substring(1);

        for (int i = 0; i <=pro.length() ; i++) {
            String first=pro.substring(0,i);
            String second=pro.substring(i);
            perm(first+ch+second,un);
        }

    }

    public static void main(String[] args) {
        perm("","abc");
    }
}
