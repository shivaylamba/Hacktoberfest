package LinkedList;

public class LinkedListMain {

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

//        list.insertFirst("Mohini");
//        list.insertFirst("Mohit");
//        list.display();
//
//        list.insertLast("Shobit");
//        list.display();
//
//        list.insert("Kunal",0 );
//        list.insert("Apoorv",0 );
//        list.insert("Rahul",1 );
//
////
//        list.insertFirst("Kunal");
//        list.insertFirst("Kunal");
//        list.insertFirst("Rahul");
//        list.insertFirst("Rahul");
//
//        list.duplicates();

        list.insertLast("Bhanu");
        list.insertLast("Amit");
        list.insertLast("Girja");

        LinkedList list2 = new LinkedList();
        list2.insertLast("Anuj");
        list2.insertLast("Happy");
        list2.insertLast("Manoj");

//        LinkedList m = LinkedList.merge(list, list2);
//        m.display();

        list.bubbleSort();
        list.display();
//        list2.display();


    }

}
