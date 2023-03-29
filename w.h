#include<stdio.h>
#include<stdlib.h>

#define DEFAULT -1

unsigned char calcBit(unsigned int num){
    unsigned char len = 1;
    while (num >= 10){
        len++;
        num /= 10;
    }
    return len;
}

// unsigned int to a string, return NULL if num is 0;
char * myItoa(int num){
    if (!num){
        char * r = (char *) malloc(2);
        r[0] = '0';
        r[1] = 0;
        return r;
    }
    unsigned char len = calcBit(num);
    // rember to free
    char * astring = (char*) malloc(len+1);
    astring[len--] = 0;
    while(num > 0){
        astring[len--] = '0' + num % 10;
        num /= 10;
    }
    return astring;
}








