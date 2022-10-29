import java.util.Random;

import static java.lang.Math.*;

public class RandomNumberGenerator {
    public static void main(String[] args) {
        Random random = new Random();
        for(int i =0; i<1000; i++){
            int num = random.nextInt(500);
            System.out.print(num+ " ");
        }
    }
}
