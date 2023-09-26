package binarysearch;
//        Allocate Books | Medium
//        
//        Problem Description:
//        Given an array of integers A of size N and an integer B.
//        The College library has N books. The ith book has A[i] number of pages.
//        You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.
//        A book will be allocated to exactly one student.
//        Each student has to be allocated at least one book.
//        Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
//        Calculate and return that minimum possible number.
//        NOTE: Return -1 if a valid assignment is not possible.
//
//        Example Input
//        Input 1:
//        A = [12, 34, 67, 90]
//        B = 2
//        Output 1:
//        113

public class AllocatedBooks {
    public int books(int[] A, int B) {
        if (B > A.length) return -1;
        int low = A[0];
        int high = 0;
        for (int i = 0; i < A.length; i++) {
            high = high + A[i];
            low = Math.min(low, A[i]);
        }
        int res = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isPossible(A, mid, B)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // return res -> this is also correct
        return low;
    }
    static boolean isPossible(int[] A, int pages, int students) {
        int cnt = 0;
        int sumAllocated = 0;
        for (int i = 0; i < A.length; i++) {
            if (sumAllocated + A[i] > pages) {
                cnt++;
                sumAllocated = A[i];
                if (sumAllocated > pages) return false;
            } else {
                sumAllocated += A[i];
            }
        }
        if (cnt < students) return true;
        return false;
    }
}
