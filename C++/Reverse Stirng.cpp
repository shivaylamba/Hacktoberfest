
 // Using vector
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};


//Using Iteration
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r = s.size()-1;
        while(l<=r){
            swap(s[l++],s[r--]);
        }
    }
};


// So this is basically a leetcode solution.... of the problem no 344. Reverse String ......... How to Reverse a String .....
