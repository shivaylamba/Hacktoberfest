
class userexception extends Exception{
    public userexception(String message){
        super(message);
    }

}

public class exception {

    static void checkAge(int age ) throws userexception{
        if (age<=18 ){
            throw new userexception("Age is less than 18 not elogible to vote:");
        }
        else {
            System.out.println("Eligible to vote:");
        }
    }
    public static void main(String[] args) {
        try{
            checkAge(25);
        }
        catch(userexception e){
            System.out.println("exception :"+ e.getMessage());
        }
    }
}