
import java.util.Scanner;

public class Salary {
    public static void main(String[] args) {
		// Write your code here
		Scanner s = new Scanner(System.in);
        int basic = s.nextInt();
        char grade = s.next().charAt(0);
        
        double hra = (0.2)*basic;
        double da = (0.5)*basic;
        int allow = 1300;
        
        if(grade == 'A'){
            allow = 1700;
        }
        else if(grade == 'B'){
            allow = 1500;
        }
        else{
            allow = 1300;
        }
        double pf = (0.11)*basic;
        int totalSalary = (int) Math.round((basic + hra + da + allow - pf));
        
        System.out.println(totalSalary);
	}
}
