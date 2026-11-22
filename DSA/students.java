class students {
    int id ; String name ;

    students (int id , String name ){
        this.id = id ;
        this.name = name;
    }

    void display(){
        System.out.println(id +" "+name );
    }
    public static void main (String [] args){
        students s1 = new students(1, "Saurabh");
        s1.display();
    }


    
}
