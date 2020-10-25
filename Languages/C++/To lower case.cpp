class Solution {
public:
    string toLowerCase(string str) {
        // // return str.ToLowerCase();
        // string ans=NULL;
        // string :: iterator itr;
        // int val;
        // // for(itr=str.begin();itr<str.end();itr++){
        // //     if(val>=65 & val<=90)
        // //         // ans=ans+(char)((itr->first)-32);
        // //         cout<<*itr<<" ";
        // //     ans=ans+itr;
        // // }
        // for(char c:str){
        //     if(c>'Z')
        //         c=c+32;
        //     ans=ans+c;
        // }
        //     return ans;
        
        for(int i = 0; i < str.length(); i++){
        if(str[i] >= 65 and str[i] <= 90){
            str[i] += 32;
        } 
    }
    return str;
    
    }
};
