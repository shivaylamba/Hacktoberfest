class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        int l = nums.length;
        List<List<Integer>> ol = new ArrayList<>();
        if(l<4){
            return ol;
        }
        
        Arrays.sort(nums);
        HashSet<String> hs = new HashSet<>();
        for(int i = 0 ; i < l-3 ; i++ ){
            for(int j = i+1; j<l-2; j++){
                
                int lo = j+1;
                int hi = l-1;
                while(lo<hi){
                       
                    if(nums[i] + nums[j] + nums[lo] + nums[hi] == target){
                        String s = "" + nums[i] + nums[j] + nums[lo] + nums[hi];
                        if(hs.contains(s) == false){
                        
                            List<Integer>  il = new  ArrayList<>(); 
                            il.add(nums[i]);
                            il.add(nums[j]);
                            il.add(nums[lo]);
                            il.add(nums[hi]);                        

                            ol.add(il);
                            hs.add(s);
                        }
                        lo++;
                        hi--;
                    }
                    else if(nums[lo] + nums[hi] < target - nums[i] - nums[j]){
                        lo++;
                    }else if(nums[lo] + nums[hi] > target - nums[i] - nums[j]){
                        hi--;
                    }
                }   
                
            }
        }
        
        return ol;
    }
}
