class stockexception extends Exception{
    public stockexception(String message){
        super(message);
    }

}

public class outofstockexception {
    static void checkorder(int order) throws  stockexception{
        if (order>500){
            throw new stockexception("request greater:");
        }
        else {
            System.out.println("Order placed");
        }

    }
    public static void main(String[] args) {
        try {
            checkorder(1900);
        } catch (Exception e) {
            // TODO: handle exception
            System.out.println(e.getMessage());
        }
    }
    
}
