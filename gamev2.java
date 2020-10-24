//import javafx.scene.shape.Circle;
package mygame;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

class Game extends JPanel implements Runnable {
    private boolean play=false;
    private int score1=0;
    private int score2=0;
    private paddle p1=new paddle(225,75);
    private paddle p2=new paddle(225,550);
    private puck pck = new puck(225,450);
    int a[];
    public Game(int a[],JFrame frame){               
        frame.getContentPane().setBackground(Color.BLACK);
        frame.add(this);
        frame.setSize(450,650);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);
        this.a=a;
    }
    public void paint(Graphics g){
        super.paint(g);
        // actual size 625 * 450        
                g.setColor(Color.BLACK);
        g.fillRect(0,0,450,625);

        g.setColor(Color.RED);
        g.fillRect(0,312,10,625);
        g.fillRect(0,615,150,10);
        g.fillRect(300,615,150,10);
        g.fillRect(440,312,10,313);

            
        g.setColor(Color.BLUE);
        g.setFont(new Font("serif",Font.BOLD,36));
        g.drawString(String.valueOf(score1),28,303);


        g.setColor(Color.RED);
        g.setFont(new Font("serif",Font.BOLD,36));
        g.drawString(String.valueOf(score2),28,348);

        g.setColor(Color.BLUE);
        g.fillRect(0,0,10,312);
        g.fillRect(0,0,150,10);
        g.fillRect(300,0,150,10);
        g.fillRect(440,0,10,312);
        
        g.setColor(Color.GRAY);
        g.drawOval(150,550,150,150);
        g.drawOval(150,237,150,150);
        g.drawLine(0,312,450,312);        
        g.drawOval(150,-75,150,150);        
        g.setColor(Color.green);
        g.fillOval(p1.x-24,p1.y-24,48,48);
        //g.fillRect(s1px,s1py,60,10);

        g.setColor(Color.ORANGE);
        g.fillOval(p2.x-24,p2.y-24,48,48);        
        //g.fillRect(s2px,s2py,60,10);


        g.setColor(Color.CYAN);
        g.fillOval(pck.x-12,pck.y-12,24,24);

        g.setColor(Color.BLACK);
        g.fillOval(p1.x-12,p1.y-12,24,24);
        g.fillOval(p2.x-12,p2.y-12,24,24);
        g.dispose();
    }

    public void run(){
        while(true){
        p1.move(a[0], a[1], a[2], a[3], 0.001);
        p1.check_horizontal_bounds();
        p1.check_lower_boundary();

        p2.move(a[4], a[5], a[6], a[7], 0.001);
        p2.check_horizontal_bounds();
        p2.check_upper_boundary();

        pck.move(0.001);

        this.repaint();
        for(int i=0;i<8;i++)a[i]=0;
        try{
        Thread.sleep(10);}
        catch(InterruptedException e){}
        }
    }
    
}
class keys extends JPanel implements KeyListener,Runnable{
    int a[];
    keys(int a[],JFrame frame){this.a=a;frame.add(this);addKeyListener(this);}    
    public void run(){
                
        while(true);
            
    }
    
    public void keyPressed(KeyEvent keyEvent) {
        if(keyEvent.getKeyCode()==KeyEvent.VK_RIGHT){
            a[7]++;
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_LEFT) {
            a[6]++;
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_DOWN) {
            a[5]++;
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_UP) {
            a[4]++;
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_A) {
            a[2]++;
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_D) {
            a[3]++;
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_S) {
            a[1]++;
        }
        else if(keyEvent.getKeyCode()==KeyEvent.VK_W) {
            a[0]++;
        }
    }
        @Override
    public void keyReleased(KeyEvent keyEvent) {

    }
@Override
    public void keyTyped(KeyEvent keyEvent) {

    }

}

public class gamev2{
    public static void main(String[] args) throws InterruptedException {
        int a[]=new int[8];
         JFrame frame = new JFrame("game-v1");           
         Thread game = new Thread(new Game(a,frame));
        Thread k =new Thread(new keys(a,frame)); 
       
        game.start();
        k.start();
    }
}
