#include <stdio.h>
#include <libsx.h>
#include <stdlib.h>

#define DEFAULT -1
void myStrcpy(char * target, char * src, char end){
    for (int i = 0; src[i] != end && src[i]; ++i){
        target[i] = src[i];
    }
}
int myStrlen(char * src, char end){
    int len = 0;
    for (; src[len] && src[len] != end; ++len);
    return len;
}
// split src string by char s
char ** split(char * src, char s){
    int strnum = 1;
    for (int i = 0; src[i]; ++i){
        if (src[i] == s){
            ++strnum;
        }
    }
    // return stuff
    char ** splites = (char**)malloc((strnum + 1) * sizeof(char*));
    if (!splites){ exit(-1);}
    splites[strnum] = NULL;
    int sub = 0;
    for (int i = 0; i < strnum - 1; ++i){
        int l = myStrlen(src, s);
        char * newString = (char *) malloc(l + 2);
        if (!newString){ exit(-1);}
        newString[l + 1] = 0;
        newString[l] = s;
        myStrcpy(newString, src, s);
        src += l + 1;
        splites[sub++] = newString;
    }
    
    int lastLen = strlen(src);
    char * lastString = (char *) malloc(lastLen + 1);
    lastString[lastLen] = 0;
    for (int i = 0; i < lastLen; ++i){
        lastString[i] = src[i];
    }
    splites[sub++] = lastString;
    return splites;
}

char * combineTwoString(char * s1, int sub1, char * s2, int sub2){
    if (sub1 == DEFAULT){
        sub1 = strlen(s1) - 1;
    }
    if (sub2 == DEFAULT){
        sub2 = strlen(s2) - 1;
    }
    int l = sub1 + sub2 + 3;
    char * s = (char *)malloc(l);
    if (!s){ exit(-1);}
    s[l - 1] = 0;
    int sub = 0;
    for (int i = 0; i <= sub1; ++i){
        s[sub++] = s1[i];
    }
    for (int i = 0; i <= sub2; ++i){
        s[sub++] = s2[i];
    }
    return s;
}

// combine big chars;
char * combineBigChars(char * b1, char * b2){
    char ** sp1 = split(b1, '\n');
    char ** sp2 = split(b2, '\n');
    char ** cb = (char**)malloc(5 * sizeof(char*));
    if(!cb){ exit(-1);}
    for (int i = 0; i < 5; ++i){
        cb[i] = combineTwoString(sp1[i], myStrlen(b1, '\n') - 1, sp2[i], DEFAULT);
    }
    char * res = cb[0];
    if (!res){ exit(-1);}
    for (int i = 1; i < 5; ++i){
        res = combineTwoString(res, DEFAULT, cb[i], DEFAULT);
    }
    return res;
}
