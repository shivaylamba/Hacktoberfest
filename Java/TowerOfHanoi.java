public class TowerOfHanoi {
    static void ToH(int n, char A, char B, char C)
    {
        if (n == 1)
        {
            System.out.println("Move 1 from " +  A + " to " + C);
            return;
        }
        ToH(n-1, A, C, B);//move n-1 rings from a to c

        System.out.println("Move " + n + " from " +  A + " to " + C); //finaly move the desired [nth] block from a to B[here in variab le C)
        ToH(n-1, B, A, C);
    }


    public static void main(String args[])
    {
        int n = 3;
        ToH(n, 'A', 'B', 'C');
    }
}
