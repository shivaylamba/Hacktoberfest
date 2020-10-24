package mygame;
import java.lang.Math;
public class puck{
    public int x,y,radius,speed,mass;
    public double angle;
    public puck(int x,int y){
        this.x = x;
        this.y = y;
        this.radius = 12;
        this.speed = 450;
        this.mass = 100;
        this.angle = 0;
    }
    public void move(double time_delta){
        this.x += Math.sin(angle) * speed * time_delta;
        this.y -= Math.cos(angle) * speed * time_delta;
        this.speed *= 0.998;
    }

    public void check_boundary(){
        // right side
        if(x > 428){
            x = 2*428-x;
            angle = -angle;
        }

        // left side
        else if(x < 32){
            x =32+(32-x); 
            angle = -angle;
        }
        // bottom
        if(y > 603 ){
            y = 2*603-y;
            angle = Math.PI - angle;
        }
        // top
        else if(y < 10){
            y = 20-y;
            angle = Math.PI - angle;
        }
    }
    void add_vectors(double angle[], double length[]){
        double x = Math.sin(angle[0]) * length[0] + Math.sin(angle[1]) * length[1];
        double y = Math.cos(angle[0]) * length[0] + Math.cos(angle[1]) * length[1];

        length[0] = Math.hypot(x, y);
        angle[0] = Math.PI / 2 - Math.atan2(y, x);
    }

    boolean collision_paddle(mygame.paddle p){
        /**
        Checks collision between circles using the distance formula:
        distance = sqrt(dx**2 + dy**2)
        **/
        int dx = this.x - p.x;
        int dy = this.y - p.y;

        // distance between the centers of the circle
        double distance = Math.hypot(dx, dy);

        // no collision takes place.
        if (distance > this.radius + p.radius)
            return false;

        // calculates angle of projection.
        double tangent = Math.atan2(dy, dx);
        double temp_angle = Math.PI / 2 + tangent;
        int total_mass = this.mass + p.mass;

        // The new vector for puck formed after collision.
        double ang[]= {this.angle,temp_angle};
        double len[]= {this.speed * (this.mass - p.mass) / total_mass, 2 * p.speed * p.mass / total_mass};

        add_vectors(ang,len);
        this.angle=ang[0]; this.speed=(int)len[0]; 

        // speed should never exceed a certain limit.
        if (this.speed > 1500)
            this.speed = 1500;

        // new vector for paddle without changing the speed.
        ang[0] = p.angle;
        ang[1] = temp_angle + Math.PI;
        len[0] = p.speed * (p.mass - this.mass) / total_mass;
        len[1] =  2 * this.speed * this.mass / total_mass;

        add_vectors(ang,len);
        p.angle = ang[0];

        // To prevent puck and paddle from sticking.
        double offset = 0.5 * (this.radius + p.radius - distance + 1);
        this.x += Math.sin(temp_angle) * offset;
        this.y -= Math.cos(temp_angle) * offset;
        p.x -= Math.sin(temp_angle) * offset;
        p.y += Math.cos(temp_angle) * offset;
        return true;
    }


    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
}
