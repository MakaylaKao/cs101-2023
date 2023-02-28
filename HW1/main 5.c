/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int main() {
    int a[] = {-9, 8, 7, 6, 5, -4, 3, -2, 1};
    int i = 4;
    int n = sizeof(a)/sizeof(a[0]);
    int j, k, t;
    for (j = 0 ; j < n-1 ; j++) {
        for (k = j+1; k < n; k++) {
            if (a[j] < a[k]) {
                t = a[j];
                a[j] = a[k];
                a[k] = t;
            }
        }
    }
    printf("%d \n",  a[i-1]);
    return 0;
}