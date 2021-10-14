/* Longest common substring */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int LCSS(char *str1, char *str2, int l1, int l2)
{
    int LCS[l2][l1];
    int result =0;

    for(int i=0;i<l2;i++)
    {
        for(int j=0;j<l1;j++)
        {
            if(i==0 | j==0)
            {
                LCS[i][j] = (str1[i]==str2[j]);
            }

            else if(str1[i]==str2[j])
            {
                LCS[i][j] = LCS[i-1][j-1]+1;
                result= std::max(result,LCS[i][j]);
            }
            else
            {
                LCS[i][j]=0;
            }
        }
    }

    return result;
}

int main()
{
    char str1[] = "lclc";
    char str2[] = "clcl";
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    printf("%d",LCSS(str1,str2,l1,l2));

    return 0;
}
