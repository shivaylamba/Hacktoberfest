import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class TicketBookingQueue {
    public static void main(String[] args) {
        Queue<String> bookingQueue = new LinkedList<>();
        Scanner sc = new Scanner(System.in);

        System.out.println("Ticket Booking Queue");
        System.out.println("Commands: add <name>, serve, peek, size, exit");

        while (true) {
            System.out.print("> ");
            String cmd = sc.next();

            if (cmd.equalsIgnoreCase("add")) {
                String name = sc.next();
                bookingQueue.offer(name); // enqueue
                System.out.println("Added: " + name + " | Queue: " + bookingQueue);

            } else if (cmd.equalsIgnoreCase("serve")) {
                String served = bookingQueue.poll(); // dequeue
                if (served == null) {
                    System.out.println("No one in queue.");
                } else {
                    System.out.println("Served: " + served + " | Queue: " + bookingQueue);
                }

            } else if (cmd.equalsIgnoreCase("peek")) {
                String next = bookingQueue.peek();
                System.out.println(next == null ? "Queue empty." : "Next: " + next);

            } else if (cmd.equalsIgnoreCase("size")) {
                System.out.println("Size: " + bookingQueue.size());
                
            } else if (cmd.equalsIgnoreCase("exit")) {

 break;
            } else {
                System.out.println("Unknown command.");
            }
        }
        sc.close();
    }
}
