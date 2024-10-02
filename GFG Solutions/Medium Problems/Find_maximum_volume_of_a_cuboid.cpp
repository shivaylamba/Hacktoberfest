/*
Find maximum volume of a cuboid
You are given a perimeter & the area. Your task is to return the maximum volume that can be made in the form of a cuboid from the given perimeter and surface area.
Note: Round off to 2 decimal places and for the given parameters, it is guaranteed that an answer always exists.
Examples
Input: perimeter = 22, area = 15
Output: 3.02
Explanation: The maximum attainable volume of the cuboid is 3.02
Input: perimeter = 20, area = 5
Output: 0.33
Explanation: The maximum attainable volume of the cuboid is 0.33
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints :
1 ≤ perimeter ≤ 109
1 ≤ area ≤ 109
*/
class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here
         /*
            as V = lbh, 
    => V = l (A/2-(lb+lh)) {from equation (ii)} 
    => V = lA/2 – l^2(b+h) 
    => V = lA/2 – l^2(P/4-l) {from equation (i)} 
    => V = lA/2 – l^2P/4 + l^3 —-(iii)
    Now differentiate V w.r.t l for finding maximum of volume. 
    dV/dl = A/2 – lP/2 + 3l^2 
    After solving the quadratic in l we have l = (P – (P^2-24A)^1/2) / 12 
    Substituting value of l in (iii), we can easily find the maximum volume.
    */
    double ans =
            (pow((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12, 2) *
             ((perimeter / 4) -
              (2 * ((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12))));

        return ans;
    }
};