class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> l=new ArrayList<>();
        
        listpal(0,s,l,"",new ArrayList<String>());
        return l;
        
    }
     public static void listpal(int in,String s,List<List<String>> l,String t,ArrayList<String> ds)
     {
         if(in==s.length())
         {l.add(new ArrayList<String>(ds));
             return;
         }
         for(int i=in;i<s.length();i++)
         {
                if(pal(s,in,i))
            {ds.add(s.substring(in,i+1));
            listpal(i+1,s,l,t,ds);
            ds.remove(ds.size()-1);

         }}}
         public static boolean pal(String s,int st,int e)
         {
           
             while(st<=e)
             {
                 if(s.charAt(st++)!=s.charAt(e--))
                 return false;
             }
             return true;
         }
}
