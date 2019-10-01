package com.codingblocks;

import java.util.Arrays;
import java.util.BitSet;

public class Demo {

    public static void main(String[] args) {

        String cs = "11010110100011";
        BitSet bitset = new BitSet(cs.length());

        int bitcounter = 0;

        for(Character ch : cs.toCharArray()){
            if (ch.equals('1')){
                bitset.set(bitcounter);
            }
            bitcounter++;
        }

        for (int i = 0; i < bitset.length(); i++) {
            System.out.print(bitset.get(i) + " ");
        }
        System.out.println();

        byte[] arr = bitset.toByteArray();

        System.out.println(Arrays.toString(arr));
        System.out.println(arr.length);

    }

}
