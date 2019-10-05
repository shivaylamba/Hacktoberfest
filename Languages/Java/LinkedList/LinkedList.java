package LinkedList;

public class LinkedList {

    private Node head;
    private Node tail;

    private int size;

    public LinkedList(){
        size = 0;
    }

    public void insertFirst(String value){

        Node node = new Node(value);
        node.next = head;
        head = node;

        if(tail == null){
            tail = head;
        }

        size++;
    }

    public void insertLast(String value){

        if(size == 0){
            insertFirst(value);
            return;
        }
        Node node = new Node(value);
        tail.next = node;
        tail = node;

        size++;
    }

    // insert at particular index
    public void insert(String value, int index){

//        head = insertRec(index, value, head);
        // OR

        if(index == 0){
            insertFirst(value);
            return;
        }else if(index == size){
            insertLast(value);
            return;
        }

//        Node previous = get(index - 1);

        Node previous = head;

        for (int i = 1; i < index ; i++) {
            previous = previous.next;
        }

        Node node = new Node(value, previous.next);
        previous.next = node;

        size++;
    }

    public String deleteFirst(){

        String value = head.value;

        head = head.next;

        if(head == null){
            tail = null;
        }

        size--;

        return value;
    }

    public String deleteLast(){

        if(size < 2){   // Only 1 item
            return deleteFirst();
        }

//        Node node = head;
//
//        while(node.next != tail){
//            node = node.next;
//        }

        // OR

        Node node = get(size - 2);

        String value = tail.value;
        tail = node;
        tail.next = null;

        size--;

        return value;

    }

    public Node get(int index){
        Node node = head;

        for (int i = 0; i < index; i++) {
            node = node.next;
        }

        return node;
    }

    // Delete from particular index
    public String delete(int index){
        if(index == 0){
            return deleteLast();
        }
        if(index == size - 1){
            return deleteLast();
        }

        Node prev = get(index - 1);
        String t = prev.next.value;
        prev.next = prev.next.next;

        size--;

        return t;
    }

    // use when not using tail or size
    public Node insertRec(int index, String value, Node node){

        if(index == 0){
            Node n = new Node(value, node);
            size++;
            return n;
        }
        node.next = insertRec(index - 1, value, node.next);
        return node;
    }

    public Node find(String value){

        Node node = head;
        while(node != null){
            if(node.value.equals(value)){
                return node;
            }
            node = node.next;
        }
        return null;
    }

    // Reverse linked list
    public void reverse(){
//        reverse(head);
//         OR

        if(size < 2){   // list of size 1
            return;
        }

        Node prev = null;
        Node present = head;
        Node next = present.next;

        tail = present;

        while(present != null){
            present.next = prev;

            prev = present;
            present = next;
            if(next != null){
                next = next.next;
            }
        }

        head = prev;
    }
    private void reverse(Node node) {
        if(node == tail){
            head = tail;
            return;
        }

        reverse(node.next);

        tail.next = node;
        tail = node;
        tail.next = null;
    }

    public void display(){

        Node node = head;
        while(node != null){ // or (node.next != null)
            System.out.print(node.value + " -> ");
            node = node.next;
        }
        System.out.println("END");
    }

    private class Node{

        private String value;
        private Node next;

        public Node(String value) {
            this.value = value;
        }

        public Node(String value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    // correct for if any node is empty
    public void odd_even(){
        Node odd_h = null;
        Node even_h = null;
        Node even_t = null;
        Node odd_t = null;

        Node node = head;

        while(node != null){

            if(node.value.length() % 2 == 0){
                if(even_h == null){
                    even_h = node;
                    even_t = node;
                }else{
                    even_t.next = node;
                    even_t = node;
                }

            }else{
                if(odd_h == null){
                    odd_h = node;
                    odd_t = node;
                }else{
                    odd_t.next = node;
                    odd_t = node;
                }

            }

            node = node.next;
        }

        even_t.next = odd_h;

        head = even_h;
        tail = odd_t;

        tail.next = null;
    }

    public void duplicates(){

        Node node = head;

        while(node.next != null){
            if(node.next != null && node.value.equals(node.next.value)){
                node.next = node.next.next;
                size--;
            }else{
                node = node.next;
            }
        }

        tail = node;
        tail.next = null;
    }

    public static LinkedList merge(LinkedList first, LinkedList second){

        Node f = first.head;
        Node s = second.head;

        LinkedList list = new LinkedList();
        while(f != null && s != null){
            if(f.value.compareTo(s.value) > 0){
                list.insertLast(s.value);
                s = s.next;
            }else{
                list.insertLast(f.value);
                f = f.next;
            }
        }

        while(f != null){
            list.insertLast(f.value);
            f = f.next;
        }
        while(s != null){
            list.insertLast(s.value);
            s = s.next;
        }

        return list;
    }

    public Node mid(){
        Node slow = head;
        Node fast = head;

        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    public void bubbleSort(){
        bubbleSort(this.size - 1, 0);
    }
    private void bubbleSort(int row, int col) {

        if(row == 0){
            return;
        }
        if(col < row){

            Node first = this.get(col);
            Node second = this.get(col + 1);

            if(first.value.compareTo(second.value) > 0){
                // swap
                if(first == head){
                    head = second;
                    first.next = second.next;
                    second.next = first;
                }else if(second == tail){
                    Node prev = get(col - 1);
                    prev.next = second;
                    tail = first;
                    first.next = null;
                    second.next = tail;
                }else{
                    Node prev = get(col - 1);
                    prev.next = second;
                    first.next = second.next;
                    second.next = first;
                }
            }
            bubbleSort(row , col + 1);
        }else{
            bubbleSort(row - 1, 0);
        }

    }

}
