/*
Alien Dictionary
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Examples :

Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Input: n = 3, k = 3, dict = {"caa","aaa","aab"}
Output: 1
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
Expected Time Complexity: O(n * |s| + k)
Expected Auxillary Space: O(k)

Constraints:
1 ≤ n≤ 104
1 ≤ k ≤ 26
1 ≤ Length of words ≤ 50
*/
// User function Template for Java

class Solution {
     public String findOrder(String [] dict, int N, int K){
        
        Map<Character,List<Character>> map=new HashMap<>();
        for(String word:dict){
            for(char c:word.toCharArray()){
                map.put(c,new ArrayList<>());
            }
        }
        
        
        for(int i=1;i<N;i++){
            
            for(int j=0;j<Math.min( dict[i-1].length() , dict[i].length() );j++){
                if(dict[i-1].charAt(j)!=dict[i].charAt(j)){
                    map.get(dict[i-1].charAt(j)).add(dict[i].charAt(j));
                    break;
                }
            }
            
        }
        
        Set<Character> vis = new HashSet<>();
        Stack<Character> st = new Stack<>();
        
        for(Character k:map.keySet()){
            if(!vis.contains(k))    topologicalSort(map,st,vis,k);
        }
        
        String ans="";
        while(!st.isEmpty()){
            ans+=st.pop();
        }
        
        return ans;
    }
    void topologicalSort(Map<Character,List<Character>> map, Stack<Character> st, Set<Character> vis,char c){
        vis.add(c);
        
        for(Character nbr:map.get(c)){
            if(!vis.contains(nbr))  topologicalSort(map,st,vis,nbr);
        }
        
        st.push(c);
    }
}