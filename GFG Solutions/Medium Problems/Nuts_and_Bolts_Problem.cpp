/*
Nuts and Bolts Problem
Given a set of n nuts & bolts. There is a one-on-one mapping between nuts and bolts. You have to Match nuts and bolts efficiently. Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means the nut can only be compared with the bolt and the bolt can only be compared with the nut to see which one is bigger/smaller.
The elements should follow the following order: { !,#,$,%,&,*,?,@,^ }

Note: Make all the required changes directly in the given arrays, output will be handled by the driver code.

Examples

Input: n = 5, nuts[] = {@, %, $, #, ^}, bolts[] = {%, @, #, $ ^}
Output: 
# $ % @ ^
# $ % @ ^
Explanation: As per the order # should come first after that $ then % then @ and ^. 
Input: n = 9, nuts[] = {^, &, %, @, #, *, $, ?, !}, bolts[] = {?, #, @, %, &, *, $ ,^, !}
Output: 
! # $ % & * ? @ ^
! # $ % & * ? @ ^
Explanation: We'll have to match first ! then  # , $,  %,  &,  *,  @,  ^,  ? as per the required ordering.
Expected Time Complexity: O(n(logn))
Expected Auxiliary Space: O(log(n))

Constraints:
1 <= n <= 9
The arrays 'nuts' and 'bolts' can only consist of the following elements: {'@', '#', '$', '%', '^', '&', '?', '*', '!'}.
All the elements of arrays 'nuts' and 'bolts' should be unique.
*/
/*
    MOST OPTIMZED APPROACH
Time Complexity O(n)
Space Complexity O(n);
*/
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        unordered_map<char,int> map;
        for(int i = 0 ;i<n;i++)   map[bolts[i]]++;
         for(int i = 0 ;i<n;i++)   map[nuts[i]]++;
        vector<char> vec = { '!','#','$','%','&','*','?','@','^'} ;
        int j = 0;
        for(int i =0;i<9;i++){
            if(map[vec[i]]==2){
                nuts[j] = bolts[j] = vec[i];
                j++;
            }
        }

    }
};
/*
    OPTIMZED APPROACH
Time Complexity O(n^log(n))
Space Complexity O(n);
*/
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        unordered_map<char,int> map;
        for(int i = 0 ;i<n;i++)   map[bolts[i]]++;
        for(int i = 0;i<n;i++){
            if(map.find(nuts[i])!=map.end()){
                bolts[i] = nuts[i];
            }
        }
        sort(nuts,nuts+n);
        sort(bolts,bolts+n);

    }
};
/*
    OPTIMZED APPROACH But Long Methods
Time Complexity O(n^log(n))
Space Complexity O(log(n));
*/
int partition(char arr[], int low,  
            int high, char pivot) 
{ 
    int i = low; 
    char temp1, temp2; 
      
    for(int j = low; j < high; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            temp1 = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp1; 
            i++; 
        }  
        else if(arr[j] == pivot) 
        { 
            temp1 = arr[j]; 
            arr[j] = arr[high]; 
            arr[high] = temp1; 
            j--; 
        } 
    }  
    temp2 = arr[i]; 
    arr[i] = arr[high]; 
    arr[high] = temp2; 
  
    // Return the partition index of  
    // an array based on the pivot  
    // element of other array. 
    return i; 
} 
  
// Function which works just like quick sort 
void matchPairs(char nuts[], char bolts[], 
                int low, int high) 
{ 
    if (low < high) 
    { 
          
        // Choose last character of bolts  
        // array for nuts partition. 
        int pivot = partition(nuts, low,  
                            high, bolts[high]); 
  
        // Now using the partition of nuts 
        // choose that for bolts partition. 
        partition(bolts, low, high, nuts[pivot]); 
  
        // Recur for [low...pivot-1] &  
        // [pivot+1...high] for nuts and 
        // bolts array. 
        matchPairs(nuts, bolts, low, pivot - 1); 
        matchPairs(nuts, bolts, pivot + 1, high); 
    } 
} 