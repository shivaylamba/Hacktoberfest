/*
N meetings in one room
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 
Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
Examples :
Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
Input: n = 3, start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Expected Time Complexity: O(n*logn)
Expected Auxilliary Space: O(n)
Constraints:
1 ≤ n ≤ 105
0 ≤ start[i] < end[i] ≤ 106
*/
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        pair<int,int> arr[n+1];
        for(int i = 0 ;  i<n;i++){
            arr[i].first = end[i];
            arr[i].second = i;
        }
        sort(arr,arr+n);
        int time = arr[0].first;
        vector<int> m;
        m.push_back(arr[0].second+1);
        for(int i = 1;i<n;i++){
            if(start[arr[i].second] > time){
                m.push_back(arr[i].second+1);
                time = arr[i].first;
            }
        }
        return m.size();
        
    }
};