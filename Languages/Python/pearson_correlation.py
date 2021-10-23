
# Import those libraries 

from scipy.stats import pearsonr 



list1=[int(j) for j in input().split()]
list2=[int(i) for i in input().split()]
# Apply the pearsonr() 
corr, _ = pearsonr(list1, list2) 
print('Pearsons correlation: %.3f' % corr) 
  
