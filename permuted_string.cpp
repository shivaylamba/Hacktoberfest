
//finding all possible combinations of a given string
// how we approach 
// we are having 3 array 2 of char and 1 of int type
// 1 char array is intialized(in main) with a string you want to find permuation another char array is empty and the other integer type array is filled with 0 initially
// why we are taking these three arrays: 1 (char type)to have the string for which we want to find the all perm 2.(char type) to store result 3.(int)which help us bulding the our string array of 1 case and printing it(this thing is looping) 
// what we are doing is from the given array of string for which we had to find all permuatation 
//taking 2 pointers (not meant by really pointer , just to keep track for the arrays )  , 1 for our resulting string array  and 2nd for our integer array  (both are  pointing to index 0 for their respective array or you can say both are having the value as 0 initialy)
//for every value of the int array at inedex or position pointed by our one of pointer, if it is 0 intialize the final result char array with that character at the same  position pointed by our one of the pointers for char array (means you are coping the value(at same index) from the given array for which you had to find all combination to the final char array) and after initlizing that position make the value as 1 of the int array at the same index(for which the if condition was true)
// and after that call itself with the increment value of the pointer that is pointing to our resulting char array 
//when the value of our integer array is not 0 (means it 1) it does not intitlize the final char array with the carcter and would not call itself(means it would not go into if condition on line no 18)
// it would do that repeated step again and again , and once its final array of char is filled it will print out that array
// and backtrack and making that value of integer array which was pointed by our one of the pointer as 0 (which is having it own value of i in the previous stacktrace)
// as this process continues it will print out all posible string to output console
#include<bits/stdc++.h>
using namespace std;
void permStr(char a[],int k){
   
   static char b[10];
   static int c[10]={0};
   if(a[k]=='\0')
   {
       b[k]='\0';
       cout<<b<<endl;
   }
    for(int i=0;a[i]!='\0';i++){
        if(c[i]==0){
            c[i]=1;
            b[k]=a[i];
            
            permStr(a,k+1);
            c[i]=0;
            
        }
    }
}
int main(){
    char a[10]="ABC";
    int k=0;
    permStr(a,0);

}