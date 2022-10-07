// The BubbleSort compares each successive pair of elements in an unordered list and inverts the elements if they
//are not in order.

//The following example illustrates the bubble sort on the list {6,5,3,1,8,7,2,4} (pairs that were compared in each
//step are encapsulated in '**')

//{6,5,3,1,8,7,2,4}
//{**5,6**,3,1,8,7,2,4} -- 5 < 6 -> swap
//{5,**3,6**,1,8,7,2,4} -- 3 < 6 -> swap
//{5,3,**1,6**,8,7,2,4} -- 1 < 6 -> swap
//{5,3,1,**6,8**,7,2,4} -- 8 > 6 -> no swap
//{5,3,1,6,**7,8**,2,4} -- 7 < 8 -> swap
//{5,3,1,6,7,**2,8**,4} -- 2 < 8 -> swap
//{5,3,1,6,7,2,**4,8**} -- 4 < 8 -> swap


// Best case complexity O(n)
// Average case complexity O(n^2)
// Average case complexity O(n^2)
// pace complexity O(1)

 void bubbleSort(vector<int>numbers)
 {
    for(int i = numbers.size() - 1; i >= 0; i--) {
        for(int j = 1; j <= i; j++) {
             if(numbers[j-1] > numbers[j]) {
                swap(numbers[j-1],numbers(j));
                    }
               }
        }
 }

