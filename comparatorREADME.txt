THE ABOVE PROGRAM USES COMPARATOR FUNCTION TO SOLVE THE CONDITIONS:-



If there is given a condition that sort the vector of pairs in accordance with the first element and if the first element is same then 
sort in descending order with respect to second element.

we can use the above code which uses comparator function and does the above task in the best possible approach .


Basically the comparator function uses the fact that if the first elements are different then sort it in ascending order [return a.first<b.first]

else if the first elements are same then sort the second elements in descending order . [return a.second>b.second].
