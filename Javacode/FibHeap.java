public class FibHeap {
    public Node min;
    public int numNodes;
    
    public FibHeap() {
        this.min = null;
        this.numNodes = 0;
    }

    public void insertNode(int key, int vertVal) {
        Node x = new Node(key, vertVal);
        this.min = mergeLists(this.min, x);
        this.numNodes += 1;        
    }

    public void insertNode(Node x) {
        // part of extract min function
        this.min = mergeLists(this.min, x);
    }

    public Node mergeLists(Node a, Node b) {
        if (a == null && b == null) 
            return null;
        
        if (a == null) 
            return b;
        
        if (b == null)
            return a;
        
        Node temp = a.next;

        a.next = b.next;
        a.next.prev = a;

        b.next = temp;
        b.next.prev = b;

        return (a.key < b.key) ? a : b;
    }

    public Node extractMin() {
        if(this.min == null) {
            System.out.println("Underflow");
            return null;
        }

        else {
            Node child = this.min.child;
            if(child != null) {
                while(child.next != child) {
                    Node temp = child;
                    child.next.prev = child.prev;
                    child.prev.next = child.next;
                    child = child.next;
                    
                    temp.next = temp;
                    temp.prev = temp;
                    temp.parent = null;

                    insertNode(temp);
                }
                child.parent = null;
                insertNode(child);
            }
            Node z = this.min;
            if (z == z.next){
                this.min = null;
                return z;
            }

            else {
                this.min = z.next;
                z.next.prev = z.prev;
                z.prev.next = z.next;
                
                z.next = z;
                z.prev = z;

                // consolidate()

                return z;
            }
        }
    }

    public void consolidate() {
        int D = (int) (Math.log(this.numNodes) / Math.log(2));
        D += 1;

        Node[] array = new Node[D];
        for (Node i : array ) {
            i = null;
        }

    }

    public void printList(Node x) {
        if (x == null) {
            System.out.println("||");
            return;
        }

        Node temp = x;
        System.out.print(x.key + " --> ");
        temp = temp.next;

        while(temp != x){
            System.out.print(temp.key + " --> ");
            temp = temp.next;
        }

        System.out.println( "||");
    }

    public static void main(String[] args) {
        FibHeap H = new FibHeap();
        H.insertNode(1,0);
        H.insertNode(2,0);
        H.printList(H.min);

        H.extractMin();
        H.printList(H.min);

        H.extractMin();
        H.printList(H.min);
    }
}

class Node {
    public Node(int key, int vertVal) {
        this.key = key;
        this.vertVal = vertVal;
        this.next = this;
        this.prev = this;
    }

    public int key;
    public int vertVal; // Value of vertex in graph
    public Node child = null;
    public Node parent = null;
    public Node next = null;
    public Node prev = null;
    public boolean isMarked = false;
    public int degree = 0;
}