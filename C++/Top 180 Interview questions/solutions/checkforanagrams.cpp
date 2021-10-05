class Solution {
public:
    bool isAnagram(string s, string t) {
      // length of both should be same
        // count of each character should be same
        unordered_map<char,int> um;
        // incrementing and decrementing the hash values
        int sSize = s.size();
        int tSize = t.size();
        if(sSize!=tSize)
            return false;
        for(int i = 0 ; i<sSize ; i++)
        {
            um[s[i]]++;
        }
        for(int i = 0 ; i<tSize ; i++)
        {
            um[t[i]]--;
            if(um[t[i]] < 0)
                return false;
        }
        return true;
    }
};
// another approach to use array as the hash map
class Solution {
public:
    bool isAnagram(string s, string t) {
      // length of both should be same
        // count of each character should be same
        // incrementing and decrementing the hash values
        int sSize = s.size();
        int tSize = t.size();
        int arr[26] = {0};
        if(sSize!=tSize)
            return false;
        for(int i = 0 ; i<sSize ; i++)
        {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for(int i = 0 ; i<26 ; i++)
        {
            if(arr[i]) return false;
        }
        return true;
    }
};