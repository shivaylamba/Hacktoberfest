package LAB5;

import java.applet.Applet;
import java.awt.*;

/* <applet code="Banner.class" height="200" width="450"></applet> */
public class MovingBanner extends Applet implements Runnable {
    private String display;
    private int x, y, flag;

    public void init() {
        display = "Hello Abhinav Sharma";
        x = 10;
        y = 100;
        flag = 1;

        //the Thread was created with "this", which is an object that implements the "Runnable" interface.
        Thread t = new Thread(this, "MyThread");

        // start thread
        t.start();
    }

    // update the x co-ordinate
    private void update() {

        x = x + 10 * flag;
        if (x > 300)
            flag = -1;
        if (x < 10)
            flag = 1;
    }
    public void run() {
        while (true) {
            // Repainting the screen
            // calls the paint function
            repaint();

            update();
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

    public void paint(Graphics g) {
        g.drawString(display, x, y);
    }
}