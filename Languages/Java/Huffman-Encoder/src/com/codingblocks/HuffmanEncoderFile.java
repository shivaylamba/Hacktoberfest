package com.codingblocks;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class HuffmanEncoderFile {

    HashMap<Character, String> encoder;
    HashMap<String, Character> decoder;

    private class Node implements Comparable<Node>{
        Character data;
        int cost;   // frequency
        Node left;
        Node right;

        public Node(Character data, int cost) {
            this.data = data;
            this.cost = cost;
            this.left = null;
            this.right = null;
        }

        @Override
        public int compareTo(Node other) {
            return this.cost - other.cost;
        }
    }

    public HuffmanEncoderFile(String feeder) throws Exception {

        // create a frequency map of this feeder String
        HashMap<Character, Integer> fmap = new HashMap<>();

        for (int i = 0; i < feeder.length(); i++) {
            char cc = feeder.charAt(i);
            if(fmap.containsKey(cc)){
                int ov = fmap.get(cc);
                ov += ov;
                fmap.put(cc, ov);
            }else{
                fmap.put(cc, 1);
            }
        }

        // 2nd Step : create min heap of Trees
        Heap<Node> minHeap = new Heap<>();
        Set<Map.Entry<Character, Integer>> entrySet = fmap.entrySet();

        for(Map.Entry<Character, Integer> entry : entrySet){
            Node node = new Node(entry.getKey(), entry.getValue());
            minHeap.insert(node);
        }

        // 3. Combine nodes until one node is left in heap
        while(minHeap.size() != 1){

            Node first = minHeap.remove();
            Node second = minHeap.remove();

            Node newNode = new Node('\0', first.cost + second.cost);
            newNode.left = first;
            newNode.right = second;

            minHeap.insert(newNode);
        }

        // ft = full tree
        Node ft = minHeap.remove();

        this.encoder = new HashMap<>();
        this.decoder = new HashMap<>();

        this.initEncoderDecoder(ft, "");
    }

    // Filling encoder and decoder
    // osf = output so far
    private void initEncoderDecoder(Node node, String osf){
        if(node == null){
            return;
        }

        // leaf node
        if(node.left == null && node.right == null){
            this.encoder.put(node.data, osf);
            this.decoder.put(osf, node.data);
        }

        this.initEncoderDecoder(node.left, osf+"0");
        this.initEncoderDecoder(node.right, osf+"1");
    }

    public String encode(String source){

        String rv = "";

        for (int i = 0; i < source.length(); i++) {
            rv = rv + encoder.get(source.charAt(i));
        }

        return rv;
    }

    public String decode(String codedString){
        String rv = "";
        String key = "";

        for (int i = 0; i < codedString.length(); i++) {
            key = key + codedString.charAt(i);
            if(decoder.containsKey(key)){
                rv = rv + decoder.get(key);
                key = "";
            }
        }
        return rv;
    }


}
