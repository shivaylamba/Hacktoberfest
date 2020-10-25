#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int length = str.size()-1;
    int sum = 0;
    int count_freq = 0;
    int count_to_three=0;
    for(int i = length;i>=0;i--){
            sum += str[i]-'0';
            count_to_three++;
            if((str[i]-'0')%3==0){
                count_freq++;
                count_to_three = 0;
                sum = 0;
            }
            else  if((sum%3==0)||((count_to_three)==3)){
                count_freq++;
                count_to_three = 0;
                sum = 0;
            }
    }
    cout << count_freq <<endl;

    return 0;
}
