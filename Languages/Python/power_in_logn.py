def power(x, y): 
  
   
    res = 1
    sign = y<0 
    if sign:
        y = y* -1
    while (y > 0): 
        
        if ((y & 1) == 1) : 
            res = res * x 
  
       
        y = y >> 1
       
        
        x = x * x 
      
    if sign:
        return 1/res
    return res    
  
  
print("Power is ",power(2,0))  
print("Power is ",power(2,1))  
print("Power is ",power(2,2))  
print("Power is ",power(2,5))
print("Power is ",power(2,-3))  
       