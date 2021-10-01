# This program demonstrates Insertion sort in python 
# by sorting a list of Students (of type string) and their register numbers (of type int)

# List comprehension to input the values 
a = [input("Enter the student name followed by register number: ").split() for i in range(int(input("Enter the number of students: ")))]

# Insertion sort 
for i in range(1, len(a)): 
    k = a[i] 
    j = i-1
    while (j >= 0) and (k[1] < a[j][1]) : 
            a[j + 1] = a[j] 
            j -= 1
    a[j + 1] = k

# Display result 
print(a)
