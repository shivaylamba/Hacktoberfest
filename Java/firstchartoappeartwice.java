class Solution {
    public char repeatedCharacter(String s) {
        HashSet<Character> set=new HashSet<>();
        char ch='a';
        for(char c: s.toCharArray()){
            if(set.contains(c)){
                ch=c;
                break;
            }
            else
                set.add(c);
        }
       return ch;
    }
}
