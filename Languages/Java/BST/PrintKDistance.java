package com.codingblocks;

import java.util.Scanner;

public class PrintKDistance {

    private Node root;

    public PrintKDistance(){

    }

    public boolean isEmpty(){
        return this.root == null;
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
        if(node.data > value){
            node.left = insert(value, node.left);
        }
        if(node.data < value){
            node.right = insert(value, node.right);
        }

        return node;
    }

    public void populate(int[] nums){

        for (int i = 0; i < nums.length; i++) {
            this.insert(nums[i]);
        }
    }

    private class Node{
        private int data;
        private Node right;
        private Node left;

        public Node(int value){
            this.data = value;
        }
    }

    public Node get(int value){

        return(get(value, root));

    }
    private Node get(int value, Node node){
        if(node == null){
            return null;
        }

        if(node.data == value){
            return node;
        }

        if(node.data > value){
            return get(value, node.left);
        }else
            return get(value, node.right);
    }

    void kDown(Node node, int k)
    {
        if (node == null || k < 0)
            return;

        if (k == 0)
        {
            System.out.print(node.data);
            System.out.println(" ");
            return;
        }

        kDown(node.left, k - 1);
        kDown(node.right, k - 1);
    }

    int kDistance(Node node, Node target, int k)
    {
        if (node == null)
            return -1;

        if (node == target)
        {
            kDown(node, k);
            return 0;
        }

        int l = kDistance(node.left, target, k);

        if (l != -1)
        {

            if (l + 1 == k)
            {
                System.out.print(node.data);
                System.out.println(" ");
            }

            else
                kDown(node.right, k - l - 2);

            return 1 + l;
        }

        int dr = kDistance(node.right, target, k);
        if (dr != -1)
        {
            if (dr + 1 == k)
            {
                System.out.print(node.data);
                System.out.println(" ");
            }
            else
                kDown(node.left, k - dr - 2);
            return 1 + dr;
        }
        return -1;
    }

    public static void main(String[] args) {
        PrintKDistance bst = new PrintKDistance();

        Scanner input  = new Scanner(System.in);
        int N = input.nextInt();

        for (int i = 0; i < N; i++) {
            bst.insert(input.nextInt());
        }

        int find = input.nextInt();

        Node target = bst.get(find);

        int k = input.nextInt();

        bst.kDistance(bst.root, target, k);


    }
}
