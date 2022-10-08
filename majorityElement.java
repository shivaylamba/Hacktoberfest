
//User function Template for Java

class Solution
{
    static int majorityElement(int a[], int size)
    {
        // your code heren
        int ele=a[0];
        int freq=0;
        
        for(int i=0;i<size;i++)
        {
            if(freq==0)
            {
                
                ele=a[i];
                
            }
            if(ele==a[i])
            {
                freq++;
            }
            else{
                freq--;
            }
        }
        
        int count=0;
        
        for(int i:a)
        {
            if(i==ele)
            {
                count++;
            }
        }
        
        if(count>=(size/2)+1){
            return ele;
        }
        
        else{
            return -1;
        }
     
        
    }
}
