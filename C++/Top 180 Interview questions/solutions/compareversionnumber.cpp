class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream is1(version1);
        stringstream is2(version2);
        int num1 = 0, num2 = 0;
        char c;
        while( bool(is1 >> num1) + bool (is2 >> num2)) {
            // here is1 >> num1 - direct coversion is happening
            // from string to int wow
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
            is1 >> c; is2 >> c;
            // to proceed to the next word of the string stream
            num1 = num2 = 0;
        }
        if(num1 == num2)  return 0;
        return 0; 
    }
};