


package oop;

class MyThread implements Runnable{  // thread are created using the Runnable interface
String tName;
Thread t;  
MyThread (String threadName){  // constructor to create the thread with the user define name.
tName = threadName;
t = new Thread (this, tName);  // these particular statement is important to implement runnable interface it take two field one is the name of the class of which new thread created and other is the name of the thread.
t.start();  // explicitly start the thread execution.
}
    public void run(){  //The start() method calls the run() method and now thread execute the code in the run() method 
        try{
         for(int i = 1; i<=10;i++){  // these for loop print the "HELLO" String 10 times for each of the three thread with delay of 300 ms
             System.out.println("Hello");
             Thread.sleep(300); // the sleep() method make the thread asleep for 300ms
                }
              }
            catch(InterruptedException e){ // if there is any error then catch method throws which kind of exception it is.
                System.out.println(e);
               }
    }
}


 public class muti_thread_program{    
	public static void main(String args[]){
    //the three referance object of the MyThread class is initialized as 1 2 3
        	MyThread thread1 = new MyThread ("1");
        	MyThread thread2 = new MyThread ("2");
        	MyThread thread3 = new MyThread ("3");
         
            try{
            //join() method wait for the thread to complete its execution and join the main thread
            	thread1.t.join();//wait for thread1 to complete its execution and join the main thread
            	thread2.t.join();//wait for thread2 to complete its execution and join the main thread
            	thread3.t.join();//wait for thread3 to complete its execution and join the main thread

            }

            catch(InterruptedException e){ // if there is any error in the join() then catch() throw that paticular exception.
                System.out.println(e);
            }
            System.out.println("Good Bye");  // at the end all the three thread terminate and then main thread print the message "Byee".        

	   }
	}


 
