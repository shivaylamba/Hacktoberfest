#include <iso646.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

/*
 * Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
 * Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
 * - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock. 
 * Sample input: 07:05:45PM
 * Sample output 19:05:45
 */

int main() {
    int hora, min, seg;
    char format[2];
    scanf("%d:%d:%d%s", &hora, &min, &seg, format);
    if (strcmp(format,"PM")==0 && hora!=12) hora += 12 ;
    if (strcmp(format,"AM")==0 && hora==12) hora = 0 ;
    printf("%02d:%02d:%02d", hora, min, seg) ;
    return 0;
}
