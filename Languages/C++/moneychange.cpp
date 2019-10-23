
#include <bits/stdc++.h>
using namespace std;


int deno[] = { 1, 2, 5, 10, 20, 50, 100, 500 };
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V)
{

 vector<int> ans;


 for (int i = n - 1; i >= 0; i--) {

   while (V >= deno[i]) {
     V -= deno[i];
     ans.push_back(deno[i]);
   }
 }


//	for (int i = 0; i < ans.size(); i++)
 //	cout << ans[i] << " ";
   int  noc = ans.size();
   //printf("%d %d",noc, ans[0]);
   int freq[8] = {0};

   int seq[noc];
   for (int i = 0; i < noc; i++)
   {
     seq[i] = ans[i];
   }
   for (int i = 0; i < 8; i++)
   {
     int count = 0;
     for (int j = 0; j < noc; j++)
     {
       if(ans[j] == deno[i])
       {
         count += 1;
       }
     }

     freq[i] = count;
   }
  /* for (int i = 0; i < noc; i++)
   {
     printf(" *%d ",seq[i]);
   }
   for (int i = 0; i < 7; i++)
   {
     printf(" --%d ",freq[i]);
   }*/
   for(int i = 7; i >=0 ; i-- )
   {
       if(freq[i]!= 0)
        {
            cout << freq[i] << "x"<< deno[i] << endl;
        }
   }


}
int main(){
  int t;
  scanf(" %d",&t);
  while (t--)
  {
    int v = 0;
    scanf(" %d",&v);
    findMin(v);


  }
  return 0;
}
