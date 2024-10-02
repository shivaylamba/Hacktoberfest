/*
Integral Points Inside Triangle
Given three non-collinear points whose co-ordinates are p(p1, p2), q(q1, q2) and r(r1, r2) in the X-Y plane. Return the number of integral / lattice points strictly inside the triangle formed by these points.
Note: - A point in the X-Y plane is said to be an integral / lattice point if both its coordinates are integral.

Examples

Input: p = (0,0), q = (0,5), r = (5,0)
Output: 6
Explanation: 

As shown in figure, points (1,1) (1,2) (1,3) (2,1) (2,2) and (3,1) are the integral points inside the triangle. So total 6 are there.
Input: p = (62,-3), q = (5,-45), r = (-19,-23)
Output: 1129
Explanation: There are 1129 integral points in the triangle formed by p, q and r.
Expected Time Complexity: O(Log2109)
Expected Auxillary Space: O(1)

Constraints:
-109 ≤ x-coordinate, y-coordinate ≤ 109
*/

class Solution {
  public:
    long long int gcd(long long int a, long long int b){
        if(b==0) return a;
        else gcd(b,a%b);
        
    }
    // Finds the no. of Integral points between
// two given points.
    long long int getBP(long long int p[], long long int q[]){
    // Check if line parallel to axes
    if(p[0]==q[0]) return abs(p[1] - q[1]) -1;
    if(p[1]==q[1]) return abs(p[0] - q[0]) -1;

    return gcd(abs(p[0] - q[0]) ,abs(p[1] - q[1])) -1;
        
    }
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
        /*
        Pick's Theorem:
 A = I + (B/2) -1

A ==> Area of Polygon
B ==> Number of integral points on edges of polygon
I ==> Number of integral points inside the polygon

Using the above formula, we can deduce,
I = (2A - B + 2) / 2
        */
        long long int bp = getBP(p,q) + getBP(q,r) + getBP(p,r) + 3;
        long long int darea = abs(p[0]*(q[1] - r[1]) +
                          q[0]*(r[1] - p[1]) +
                          r[0]*(p[1] - q[1]) );
        
    return (darea - bp + 2)/2;
                                    
                                }
};