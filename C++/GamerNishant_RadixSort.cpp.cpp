/* Author - Rahul Pathak */
/*  Given n d-digit numbers in which each digit can take on up to k possible values,
    RADIX-SORT correctly sorts these numbers in O(d*(n+k)) time if the stable sort
    it uses takes O(n+k) time.
    Here, we use Counting sort as a subroutine.
*/

/* For each digit i where i varies from the least significant to the most significant digit,
    sort the input array using counting sort according to the i'th digit. */
#include <iostream>
#include <vector>
using namespace std;

int findMaxElement(vector<int> A)
{
    int maximum = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        maximum = max(maximum, A[i]);
    }
    return maximum;
}

void radixSort(vector<int> &A)
{
    int power, i = findMaxElement(A);
    // Count sort subroutine for each digit
    // This loops iterates for number of times equal to the number of digits in the maximum element
    for (power = 1; i / power != 0; power *= 10)
    {
        int result[A.size()], i, count[10] = {0};

        // Store frequency
        for (i = 0; i < A.size(); i++)
            count[(A[i] / power) % 10]++;
        // Store number of elements before the current element
        // that should appear in the sorted array
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        // placing each element at correct place in the array sorted according to
        // the particular digit
        for (i = A.size() - 1; i >= 0; i--)
        {
            result[count[(A[i] / power) % 10] - 1] = A[i];
            count[(A[i] / power) % 10]--;
        }
        for (i = 0; i < A.size(); i++)
            A[i] = result[i];
    }
}

int main()
{
    vector<int> A = {23, 2, 43, 32, 8, 13, 5, 16, 17, 1};
    radixSort(A);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << ' ';
    cout << endl;
    return 0;
}