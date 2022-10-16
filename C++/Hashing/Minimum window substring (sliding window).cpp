/* PROBLEM
find the smallest window in a string containing all characters of another string not neccessary in the same order
string - "helllaoeeo world"
pattern-"eelo"

solution-
1. Bruteforce (N^3 time)

2. sliding window + hashing

step 1- if pl>sl then return false (pl-pattern length , sl-string length)
step 2- make a frequency array of all the letters of pattern 
pattern frequency array- e-2,l-1,o-1 (fixed)
step 3- start travelling the string and make a array of frequency of letters and comapre it with array of pattern frequency.
and find the widow having pattern frequency and its length.
string frequency array - h-1,e-3,l-3,a-1,o-2
step 4 - try to contact the window to make it smallest by removing the unrequired character
step 5- every time we get a window, update min window by doing a comparision between current window and minimum window.
step 6- output the minimum window
*/

#include<iostream>
#include<climits>
#include<string>
using namespace std;

string find_window(string s,string pat){
	int sl=s.length();
	int pl=pat.length();
	//1.corner case
	if(pl>sl){
		return "NONE";
		
	}
	//2. freuency arrays for string and pattern
	int fs[256]={0};
	int fp[256]={0};
	
	for(int i=0;i<pl;i++){
		char ch=pat[i];
		fp[ch]++;
		
	}
	//3. sliding window (expansion and contraction + update the minimum length window)
	int cnt=0;
	int start=0; //left pointer for shrinking the window
	int min_len=INT_MAX;
	int start_idx=-1;
	for(int i=0;i<sl;i++){
		char ch=s[i];
		fs[ch]++;
		//mantain the count of characters matched 
		if(fp[ch]!=0 and fs[ch]<=fp[ch]){
		    cnt++;
	    }
	    //if all the characters matched
	    if(cnt==pl){
		    //start shrinking the window from the left
		    char temp=s[start];
		    //loop to remove all unwanted characters
		    while(fp[temp]==0 or fs[temp]>fp[temp]){
			    fs[temp]--;
			    start++;
			    temp=s[start];
		    }
		    //window size
		    int window_len=i-start+1;
		    if(window_len<min_len){
			    min_len=window_len;
			    start_idx=start;
			
		    }
		}
	}
	

	if(start_idx==-1){
		return "NONE";
	}
	string ans=s.substr(start_idx,min_len);
	return ans;
}

int main(){
	string s="hellloeaeo world";
	string p="eelo";
	cout<<find_window(s,p);
	
	return 0;
}






