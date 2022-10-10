#include <iostream>
#include <queue>
using namespace std;
bool islower(char &c)
    {
        return c>='a' && c<='z';
    }
    bool isupper(char &c)
    {
        return c>='A' && c<='Z';
    }
    bool isdigit(char &c)
    {
        return c>='0' && c<='9';
    }
    
    int strongPasswordChecker(string s ) {
        int n=s.length();
        
        bool lo,up,di;
        lo=up=di=false;
        
        if(n<=20)
        {
            int need_replaces=0,can_be_replaced=0;
            int need_add=(6-n)<0 ? 0:6-n;
            for(int i=0;i<n;)
            {
                if(!lo && islower(s[i]))
                    lo=true;
                if(!up && isupper(s[i]))
                    up=true;
                if(!di && isdigit(s[i]))
                    di=true;
                
                int tmp=1;
                int j=i+1;
                while(j<n && s[i]==s[j])
                {
                    j++;
                }
                tmp=(j-i);
                can_be_replaced+=tmp/3;
                
                i=j;
            }
            
            if(!lo) need_replaces+=1;
            if(!up) need_replaces+=1;
            if(!di) need_replaces+=1;
            
            int replaces=max(can_be_replaced,need_replaces);
            return max(need_add,replaces);
        }
        else
        {
            int min_deletion=n-20,need_replaces=0;
            int curr_length=0;
            priority_queue<int>pq;
            
            for(int i=0;i<n;)
            {
                if(!lo && islower(s[i]))
                    lo=true;
                if(!up && isupper(s[i]))
                    up=true;
                if(!di && isdigit(s[i]))
                    di=true;
                
                int temp=1;
                int j=i+1;
                while(j<n && s[i]==s[j])
                {
                    j++;
                }
                temp=(j-i);
                if(temp>=2)
                {
                    curr_length+=2;
                    pq.push(temp-2);
                }
                else
                    curr_length+=1;
                
                i=j;
            }
            
            if(!lo) need_replaces+=1;
            if(!up) need_replaces+=1;
            if(!di) need_replaces+=1;
            
            if(curr_length>=20)
                return min_deletion+need_replaces;
            else
            {
                int min_replacement=0;
                while(curr_length<20)
                {
                    int x=pq.top();
                    curr_length+=min(3,x);
                    x-=max(3,x);
                    min_replacement+=1;
                }
                
                min_replacement=max(min_replacement,need_replaces);
                return min_deletion+min_replacement;
            }
            
        }
            
        return 0;
    }
int main(){
    string str;
    cin>>str;
    int ans=strongPasswordChecker(str);
    cout<<5-ans;
}
