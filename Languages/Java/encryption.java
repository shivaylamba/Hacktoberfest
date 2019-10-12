package hackerrank_medium;

import java.util.Scanner;

public class encryption {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.nextLine();
        String inp = string(str, "");
        int l = inp.length();
        int sqrt = (int) Math.sqrt(l);
        int l1;
        int l2;
        if (sqrt * sqrt == l) {
            l1 = sqrt;
            l2 = sqrt;
        } else {
            l1 = sqrt;
            l2 = sqrt + 1;
        }
        if(l1*l2<l){
            l1++;
        }
        char[][] c = new char[l1][l2];
        int row = 0;

        for (int i = 0; i < l; ) {

            for (int p = 0; p < l2 && i < l; p++) {
//               System.out.println(row+" "+p);
                c[row][p] = inp.charAt(i);
                i++;
            }
            row++;
        }
        for (int i = 0; i < l2; i++) {
            for (int j = 0; j < l1; j++) {
                if (!(c[j][i] >= 65 && c[j][i] <= 130)){
                    break;
                }
                else System.out.print(c[j][i]);
            }
            if (i != l2 - 1)
                System.out.print(" ");
        }
    }

    private static String string(String str, String ans) {
        if (str.length() == 0) {
            return ans;
        }
        String ros = str.substring(1);
        if (str.charAt(0) != ' ')
            return string(ros, ans + str.charAt(0));
        else return string(ros, ans);


    }
}
