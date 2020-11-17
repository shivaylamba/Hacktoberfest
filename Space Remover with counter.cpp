#include <iostream>
#include <string>
using namespace std;

string removeSpace(string s){
    string res="";
    for(int i=0; s[i]!= 0; i++){
        if(s[i]==' '){
            continue ;
        }
        else {
            res+=s[i];
        }
    }
    return res;
}

int main() {
    string text;
    cout << "Enter any sentence";
    getline(cin, text);
    cout << "Your sentence : " << text << endl << endl;
    cout <<"After removing spaces from the sentence : " << removeSpace(text) << endl << endl;
    cout << "The number of letters in the sentence = " << removeSpace(text).length();
    return 0;
}
