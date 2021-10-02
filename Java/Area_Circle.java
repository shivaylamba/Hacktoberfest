/* OOPs concept used*/

import java.util.Scanner;

class Circle {
    private Double radius;

    public Double getArea() {
        return (3.14 * Math.pow(radius, 2));
    }

    public void setRad(double r) {
        radius = r;
    }
}

public class Area_Circle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Circle re = new Circle();
        Double rr = sc.nextDouble();
        sc.close();
        // re.radius=sc.nextInt();
        re.setRad(rr);
        System.out.println(re.getArea());

    }
}
