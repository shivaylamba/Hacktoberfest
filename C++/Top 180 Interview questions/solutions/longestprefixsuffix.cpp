int lps(string s){
    int n = s.length();
    int lps[n] = {0};
    
    int i = 0, j = 1;
    
    lps[0] = 0;
    
	while(j < n){
	       
	    if(s[i] == s[j]){
	        lps[j] = i + 1;
            j++;
	        i++;
	    }
       
	    else{
	       if(i != 0)
	           i = lps[i-1];
	        
	       else
	           lps[j] = 0;
	           j= j+1;
	           
            }
	}
    
        return lps[n-1];
	}