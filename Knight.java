import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
public class Knight {
    static PrintWriter out = new PrintWriter(System.out);
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {

                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastScanner scn = new FastScanner();
        int [][]chess = new int[5][5];
        printKnightTour(chess,0,0,0);
        out.close();
    }
    public static void printKnightTour(int[][]chess,int r,int c,int move){
        if(r<0||c<0||r>=chess.length||c>= chess.length||chess[r][c] > 0){
            return;
        }
        else if(move == (chess.length * chess.length) - 1){
            chess[r][c] = move;
            displayBoard(chess);
            chess[r][c] = 0;
            return;
        }
        chess[r][c] = move;
        printKnightTour(chess,r-2,c+1,move+1);
        printKnightTour(chess,r-1,c+2,move+1);
        printKnightTour(chess,r+1,c+2,move+1);
        printKnightTour(chess,r+2,c+1,move+1);
        printKnightTour(chess,r+2,c-1,move+1);
        printKnightTour(chess,r+1,c-2,move+1);
        printKnightTour(chess,r-1,c-2,move+1);
        printKnightTour(chess,r-2,c-1,move+1);
        chess[r][c] = 0;
    }
    public static void displayBoard(int [][]chess){
        for (int i = 0; i < chess.length; i++) {
            for (int j = 0; j < chess.length; j++) {
                System.out.print(chess[i][j] + " ");
            }
            System.out.println();
        }
    }
}
