package com.codingblocks;

import java.util.LinkedList;

public class Main {

    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();
        int[] nums = {1,2,3,4,5,6,7,8,9,11, 22, 44, 77};
        int[] nums2 = {10, 8, 20, 7,9,15,25, 30,27};

        tree.populate(nums2);

//        tree.populateWithSorted(nums);
//        tree.insert(20);
//        tree.insert(15);
//        tree.insert(25);
//        tree.insert(12);
//        tree.insert(17);
//        tree.insert(16);

//        tree.between(12, 24);

//        LinkedList<BinarySearchTree.Node> nodes = tree.sortedList();
//
//        for(BinarySearchTree.Node node: nodes){
//            System.out.println(node.getValue());
//        }

        System.out.println(tree.balanced());

    }

}
