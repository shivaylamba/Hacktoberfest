#output: displays all prime numbers in the given range
lowerRange = int(input("Enter lower range: "))  
upperRange = int(input("Enter upper range: "))  
  
for num in range(lowerRange,upperRange + 1):  
   if num > 1:  
       for i in range(2,num):  
           if (num % i) == 0:  
               break  
       else:  
           print(num)  
