/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    char a[]="AABBBCCCCddd";
    int f[256]={0};
    for (int i=0 ; i<sizeof(a)/sizeof(a[0])-1 ; i++) {
        f[a[i]]++;
    }
    for (int i=0 ; i<sizeof(f)/sizeof(f[0]) ; i++) {
        if (f[i]>0) {
            printf("%c%d", i, f[i]);
        }
    }
    printf("\n");
    return 0;
}