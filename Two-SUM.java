class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> map = new HashMap();
        
    //Filling Hash Map
        for(int i=0;i<nums.length;i++)
        {
            map.put(nums[i],i);
        }
        
    //Searching from Hash Map
       for(int i=0;i<nums.length;i++) // 2 7 11 15  target=9
        {
            if(map.containsKey(target-nums[i])){ //9-2=7
                int index=map.get(target-nums[i]);
                if(index==i) //special case 2 7 11 15  if target=4
                    continue;   // 4-nums[0]=index don't return 0,0
                return new int[]{i,index};  // 2,7
            }
        }
        return new int[]{}; 
    }
}
