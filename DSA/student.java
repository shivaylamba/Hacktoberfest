class student {

    String name ;
    int age; 

    // constructor create 

    student(){
        name = "saurabh";
        age = 20;

    }
    //contructor with 1 parameter  
    student(String a){
        name = a;
        age = 21;
    }
    student (String a , int b){
        name = a;
        age =b;
    }
    void display(){
        System.out.println(name +"  "+ age);
    }
    public static void main (String[] args){
        student s1 = new student();
        student s2 = new student("Subash");
        student s3 = new student("Rohan", 20);

        s1.display();
        s2.display();
        s3.display();
         

    }

}
