// Date:- 2/10/2023
// Finding out area of a circle using abstract class

import java.util.*;

// Abstract class Shape to represent a generic shape.
abstract class Shape {
    // Abstract method to calculate the area of the shape.
    abstract void calArea();
}

// Circle class extends Shape and represents a circle.
class Circle extends Shape {
    double radius;

    // Constructor to initialize the radius of the circle.
    Circle(double r) {
        radius = r;
    }

    // Implementation of the abstract method to calculate the area of the circle.
    public void calArea() {
        double area = 3.14 * radius * radius;
        System.out.println("Area: " + area);
    }
}

// Main1 class contains the main method for user interaction.
class Area {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Prompt the user to enter the radius of the circle.
        System.out.print("Radius: ");
        double radius = sc.nextDouble();
        
        // Create a Circle object with the user-entered radius.
        Circle c = new Circle(radius);
        
        // Calculate and display the area of the circle.
        c.calArea();
    }
}
