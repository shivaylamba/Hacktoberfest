#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInt
{
   vector<int> digits;
   int len() const;
   public :
    BigInt();
    BigInt (string);
    BigInt operator + (const BigInt&) const;
    bool operator < (const BigInt&) const;
    bool operator > (const BigInt&) const;
    bool operator == (const BigInt&) const;
    std::string str() const;
};

int main()
{
   string val1="",val2="";
   cout<<"Enter 2 numbers= "; cin>>val1>>val2;
   BigInt num1(val1),num2(val2);
   BigInt num3=num1+num2;
   cout<<"\nTheir sum is="<<num3.str();
   if(num1==num2) cout<<"\nThey are equal"<<endl;
   else if(num1<num2) cout<<endl<<num2.str()<<" is greater than "<<num1.str()<<endl;
   else if(num1>num2) cout<<endl<<num1.str()<<" is greater than "<<num2.str()<<endl;
   return 0;
}

int BigInt::len () const
{
    if(digits.size()==0) cout<<"0";
    return digits.size();
}

BigInt::BigInt() { digits.resize(0); }

BigInt::BigInt (string s) {
  int a=0;
  for(int i=0;i<s.length();i++){
    a=(int)s.at(i)-48;
    digits.push_back(a);
  }
}

string BigInt::str() const {
   string str="";
   int ln=this->len();
   for(int i=0;i<ln;i++) str=str+char(digits[i]+48);
   return str;
}

void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
      swap(str[i], str[n - i - 1]);
}

BigInt BigInt::operator + (const BigInt& a) const {
  int carry=0,s=0,tsize=this->len(),asize=a.len();
  int s_min=0,s_max=0;

  bool thismin=false,thatmin=false,isequal=false;
  if(tsize>asize){ s_min=asize; s_max=tsize; thatmin=true; }
  else if(tsize<asize){ s_min=tsize; s_max=asize; thismin=true; }
  else if(tsize==asize){ s_min=s_max=asize; isequal=true; }

  int diff=s_max-s_min;
  string res="";

  for(int i=s_min;i>0;i--){
     if(thatmin) s=this->digits[i-1+diff]+a.digits[i-1]+carry;
     else s=a.digits[i-1+diff]+this->digits[i-1]+carry;
     res+=char(s%10+48);
     carry=s/10;
  }
  if(!isequal){
  for(int j=diff;j>0;j--){
     if(thismin){
        s=a.digits[j-1]+carry;
        res+=char(s%10+48);
        carry=s/10;
     }
     else if(thatmin){
        s=this->digits[j-1]+carry;
        res+=char(s%10+48);
        carry=s/10;
     }
  }}
  if(carry) res+=char(carry+48);
  reverseStr(res);
  BigInt result(res);
  return result;
}

bool BigInt::operator < (const BigInt& a) const {
    int tsize=this->len(),asize=a.len();
    if(tsize>asize) return false;
    else if(tsize<asize) return true;
    else if(tsize==asize){
        for(int i=0;i<asize;i++){
            if(this->digits[i]>a.digits[i]) return false;
            else if(this->digits[i]<a.digits[i]) return true;
        }
    }
}

bool BigInt::operator > (const BigInt& a) const {
    int tsize=this->len(),asize=a.len();
    if(tsize>asize) return true;
    else if(tsize<asize) return false;
    else if(tsize==asize){
        for(int i=0;i<asize;i++){
            if(this->digits[i]>a.digits[i]) return true;
            else if(this->digits[i]<a.digits[i]) return false;
        }
    }
}

bool BigInt::operator == (const BigInt& a) const {
    string athis=this->str(), athat=a.str();
    if(athis==athat) return true;
    else return false;
}

