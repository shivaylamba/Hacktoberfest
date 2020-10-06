#include <stdio.h>
#include <conio.h>


void TOH(int,char,char,char);


int main()
{
    int N;
    system("cls");
    printf("Enter The Number of Disks\n");
    scanf("%d",&N);
    TOH(N,'A','B','C');
    return 0;
}

void TOH(int Disk,char First,char Mid,char Last)
{
    if (Disk>0)
    {
        TOH(Disk-1,First,Last,Mid);
        printf("\t\n\t%c -> %c",First,Last);
        TOH(Disk-1,Mid,First,Last);
    }
    
}
