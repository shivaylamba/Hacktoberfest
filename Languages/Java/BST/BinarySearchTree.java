package BST;

import java.util.LinkedList;

public class BinarySearchTree {

    private Node root;

    public BinarySearchTree(){

    }

    public boolean isEmpty(){
        return this.root == null;
    }

    public void display(){
        display(this.root, "Root Node: ");
    }
    private void display(Node node, String details){
        if(node == null){
            return;
        }

        System.out.println(details + node.value);

        display(node.left, "Left child of " + node.value + " : ");
//        System.out.println("Root Node: " + node.value);
        display(node.right, "Right child of " + node.value + " : ");

    }

    public void between(int start, int end){
        between(start, end, this.root);
    }
    private void between(int start, int end, Node node){

        if(node == null){
            return;
        }

        if(node.value >= start && node.value <= end){
            System.out.println(node.value);
        }

        if(node.value >= start){
            between(start, end, node.left);
        }
        if(node.value <= end){
            between(start, end, node.right);
        }
    }

    public void insert(int value){
        this.root = insert(value, this.root);
    }
    private Node insert(int value, Node node){

        if(node == null){
            node = new Node(value);
            return node;
        }

        // left
        if(node.value > value){
            node.left = insert(value, node.left);
        }
        if(node.value < value){
            node.right = insert(value, node.right);
        }

        // update the heights
        node.height = Math.max(height(node.left), height(node.right)) + 1;

        return node;
    }

    public boolean balanced(){
       return balanced(root);
    }
    private boolean balanced(Node node){

        if(node == null){
            return true;
        }

        return Math.abs(height(node.left) - height(node.right)) <=1  && balanced(node.left) && balanced(node.right);


    }

    public void populate(int[] nums){

        for (int i = 0; i < nums.length; i++) {
            this.insert(nums[i]);
        }
    }

    public void populateWithSorted(int[] nums){
        populateWithSorted(nums, 0, nums.length);
    }
    private void populateWithSorted(int[] nums, int start, int end){
        if(start >= end){
            return;
        }

        int mid = (start + end) / 2;

        this.insert(nums[mid]);

        populateWithSorted(nums, start, mid);
        populateWithSorted(nums, mid + 1, end);
    }


    public int height(Node node){

        if(node == null){
            return -1;
        }
        return node.height;
    }

    // read BST and create sorted Linked List

    public LinkedList<Node> sortedList(){

        LinkedList<Node> nodes = new LinkedList<>();

        return sortedList(this.root, nodes);
    }
    private LinkedList<Node> sortedList(Node node, LinkedList<Node> nodes){

        if(node == null){
            return nodes;
        }

        sortedList(node.left, nodes);
        nodes.add(node);
        sortedList(node.right, nodes);

        return nodes;
    }

    public class Node{
        private int value;
        private int height;
        private Node right;
        private Node left;

        public Node(int value){
            this.value = value;
        }

        public int getValue() {
            return value;
        }
    }
}
