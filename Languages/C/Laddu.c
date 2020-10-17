//Laddu
//A DSA Learning series problem from complexity analysis section
//Author:admin2

#include <stdio.h>
#include<string.h>

int main(void) {
	int T;
	scanf("%d",&T);
	while(T--)
	{   
	    int laddu=0;
	    int n;
	    char origin[11];
	    scanf("%d %s",&n,origin);
	    while(n--)
	    {
	       char activity[20];
	       scanf(" %s",activity);
	        if(strcmp(activity,"CONTEST_WON")==0)
	        {  int bonus=0;
	           int rank;
	            scanf("%d",&rank);
	            if(rank<20)
	            bonus=20-rank;
	            else
	            bonus=0;
	           laddu=laddu+300+bonus ;
	        }
	        else if(strcmp(activity,"TOP_CONTRIBUTOR")==0)
	        {
	            laddu=laddu+300;
	        }
	        else if(strcmp(activity,"BUG_FOUND")==0)
	        {
	            int severity;
	            scanf("%d",&severity);
	            laddu=laddu+severity;
	        }
	        else if(strcmp(activity,"CONTEST_HOSTED")==0)
	        {
	            laddu=laddu+50;
	        }
	    }
	     int month;
	    if(strcmp(origin,"INDIAN")==0)
	    {
	        month=laddu/200;
	    }
	    if(strcmp(origin,"NON_INDIAN")==0)
	    {
	        month=laddu/400;
	    }
	    printf("%d\n",month);
	}
	return 0;
}