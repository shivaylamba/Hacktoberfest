/*
Check If two Line segments Intersect
Given the coordinates of the endpoints(p1,q1, and p2,q2) of the two line segments. Check if they intersect or not. If the Line segments intersect return true otherwise return false.

Note: Please check the intersection lies within the line segments.

Examples

Input: p1=(1,1), q1=(10,1), p2=(1,2), q2=(10,2)
Output: false
Explanation:The two line segments formed by p1-q1 and p2-q2 do not intersect.
Input: p1=(10,0), q1=(0,10), p2=(0,0), q2=(10,10)
Output: true
Explanation: The two line segments formed by p1-q1 and p2-q2 intersect.
Input: p1=(5,-2), q1=(13,2), p2=(2,-3), q2=(3,0)
Output: false
Explanation: The two line segments formed by p1-q1 and p2-q2 are intersecting beyond endpoints, so it is not considerable.
Expected Time Complexity: O(1)
Expected Auxillary Space: O(1)

Constraints:
-106<=X,Y(for all points)<=106
*/
class Solution {
  public:
     int func(int p[], int q[], int r[]) {
        if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) && q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1])){
            return 1;
        }
        return false;
    }

    int direction(int p[], int q[], int r[]) {
        long long val =
            1LL * (q[1] - p[1]) * (r[0] - q[0]) - 1LL * (q[0] - p[0]) * (r[1] - q[1]);

        if (val == 0)
            return 0; 

        if(val>0){
            return 1;
        }
        else return -1;
    }

    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {

        int o1 = direction(p1, q1, p2);
        int o2 = direction(p1, q1, q2);
        int o3 = direction(p2, q2, p1);
        int o4 = direction(p2, q2, q1);

        if (o1 != o2 && o3 != o4){
            return "true";
        }
        if (o1 == 0 && func(p1, p2, q1)){
            return "true";
        }
        if (o2 == 0 && func(p1, q2, q1)){
            return "true";
        }
        if (o3 == 0 && func(p2, p1, q2)){
            return "true";
        }
        if (o4 == 0 && func(p2, q1, q2)){
            return "true";
        }
        return "false";
    }
};