public class Solution {
    
    public ArrayList<ArrayList<Integer>> threeSum(ArrayList<Integer> A) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        Collections.sort(A);
        for(int i = 0; i <= A.size()-3;i++){
            if(i==0 || A.get(i)>A.get(i-1)){
                int s = i +1 ; // start
                int e = A.size()-1; //end
                
                while(s<e){
                    if(A.get(i)+ A.get(s) + A.get(e) == 0){
                        ArrayList<Integer> pair = new ArrayList<>();
                        pair.add(A.get(i));
                        pair.add(A.get(s));
                        pair.add(A.get(e));
                        
                        res.add(pair);
                    }
                    
                    if(A.get(i)+A.get(s) + A.get(e) <0){
                        //s++;
                        int cs = s; // current start
                        while(A.get(s)==A.get(cs) && s<e){
                            s++;
                        }
                    }else{
                        int ce = e; // current end
                        while(A.get(e)==A.get(ce) && s<e){
                            e--;
                        }
                    }
                }
                
            }
            
        }
        
        return res;
    }
}
