#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int hour, minute, second;
    printf("Enter current time as\n");
    printf("let say current time is 05:15:35 \n");
    printf("You will enter 5 15 35\n");
    printf("Now enter the time to start the clock\n");
    scanf("%d %d %d", &hour, &minute, &second);
    while (1)
    {
        system("cls");
        printf("%02d : %02d : %02d ", hour, minute, second);
        fflush(stdout);
        second++;
        if (second == 60)
        {
            minute += 1;
            second = 0;
        }
        if (minute == 60)
        {
            hour += 1;
            minute = 0;
        }
        if (hour == 24)
        {
            hour = 0;
            minute = 0;
            second = 0;
        }
        sleep(1);
    }
    return 0;
}
