class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        // using two pointer approach
        int i = 0 ;
        int j = 1;
        while(j < n)
        {
           if(a[i]!=a[j]){
               i++;
               a[i]=a[j];
           }
        j++;
        }
        return i+1;
    }
};