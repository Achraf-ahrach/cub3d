#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#define INT_SIZE sizeof(int) * 8 /* Size of int in bits */

int main()
{
    int a ;
    int num, index, i;
    int bin[INT_SIZE];

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);
    a = (num << 16) + (num << 8) + num;
    printf("%d \n", a);
}