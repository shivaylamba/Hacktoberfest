package mygame; 
import java.util.*;
public class paddle{
    public int x,y,speed,mass,radius;
    public double angle;
    public paddle(int x, int y){
        this.x = x;
        this.y = y;
        this.speed = 400; 
        this.mass = 2000;
        this.angle = 0;
        this.radius = 24;
    }

    public void check_horizontal_bounds(){
        //left
        if(x <= 34)
            x = 34;
        //right
        else if(x + 24  > 440)
            x = 440 - 24;
    }

    public void check_upper_boundary(){
        if(y <= 34)
            y = 34;
        else if(y > 228)
            y=228;
    }

    public void check_lower_boundary(){
        if (y > 591)
            y = 591;
        else if (y > 336 )
            x = 336;
    }

    public void move(int up,int down,int left,int right,double time_delta){
        int dx=x,dy=y;
        x += (right - left) * speed * time_delta;
        y += (down - up) * speed * time_delta;

        dx = x - dx;
        dy = y - dy;

        angle = Math.atan2(dy, dx);
    }
    public int getX(){
        return x;
    }
    public int getY(){
        return y;
    }    
    public void reset(int start_x,int start_y){
        x = start_x;
        y = start_y;
    }
}
