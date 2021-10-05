int deno = {1,2,5,10,20,50,100,500,1000};
// in indian denominator we have a rule that 1 + 2 cannot be greater than 5
// similarly 5 + 10 cannot be greater than 20
// this is the reason the greedy approach works on this question
int target = 49;
vector<int> ans;
int n = deno.size();
for(int i =  n - 1 ; i>=0; --i)
{
 	while(deno[i]<=target)
 	{
 		target-=deno[i];
 		ans.push_back(deno[i]);
 	}
}
return ans.size();