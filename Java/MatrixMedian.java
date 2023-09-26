//Matrix Median Programming Binary Search | Medium
//        Problem Description
//        Given a matrix of integers A of size N x M in which each row is sorted.
//        Find and return the overall median of matrix A.
//        NOTE: No extra memory is allowed.
//        NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.
//
//        Problem Constraints
//        1 <= N, M <= 10^5
//        1 <= N*M <= 10^6
//        1 <= A[i] <= 10^9
//        N*M is odd
//        Input 1:
//
//        A = [   [1, 3, 5],
//        [2, 6, 9],
//        [3, 6, 9]   ]
//        Input 2:
//
//        A = [   [5, 17, 100]    ]
//
//
//        Example Output
//        Output 1:
//
//        5
//        Output 2:
//
//        17
public class MatrixMedian {
    public int findMedian(int[][] A) {
        int low = 1;
        double high = 1e9;
        int n = A.length;
        int m = A[0].length;
        while (low <=high){
            int mid = (int) ((low + high) / 2);
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += countSmallerThanEqualToMid(A[i], (int)mid);
            }
            if(cnt <= (n*m)/2){
                low = mid +1;
            }
            else {
                high = mid - 1;
            }

        }
        return low;
    }
    public static int countSmallerThanEqualToMid( int[] row, int mid){
        int low = 0, high = row.length -1;
        while (low <= high){
            int md = (low +high) /2;
            if(row[md] <= mid){
                low = md + 1;
            }
            else{
                high = md - 1;
            }
        }
        return low;
    }
}
