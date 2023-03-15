/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXLOT 69    
#define SPLOT 10     
#define NORMAL 6    
#define MAX_GEN 5    

int lot[MAXLOT];    

void init_lot(void); 
void shuf_lot(void); 
void sort_lot(void); 
void swap_lot(int i, int j); 
int sp_lot(void);    

int main(int argc, char* argv[]) {
    srand((unsigned) time(NULL)); 
    time_t curtime;
    char time_str[80];  
    int n;              

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    #ifdef ONSCREEN
        #define fp stdout
    #else
        FILE* fp;
        fp = fopen("lotto.txt", "w+");
    #endif
    fprintf(fp, "========= lotto649 =========\r\n");

    time(&curtime);
    strcpy(time_str, ctime(&curtime));
    for (int i = 0 ; i<sizeof(time_str)/sizeof(time_str[0]) ; i++) {
        if (time_str[i] == '\0') {
            time_str[i-1] = '\0';
            break;
        }
    }
    fprintf(fp, "= %s =\r\n", time_str);

    init_lot();  

    for (int i = 0 ; i<MAX_GEN ; i++) {
        shuf_lot(); 
        sort_lot();
        fprintf(fp, "[%d]: ",i+1);
        for (int j = 0 ; j<NORMAL ; j++) {
            if (i<n) {
                fprintf(fp, "%02d ", lot[j]);
            } else {
                fprintf(fp, "-- ");
            }
        }
        if (i<n) {
            fprintf(fp, "%02d\n", sp_lot());
        } else {
            fprintf(fp, "--\n");
        }
    }

    fprintf(fp, "========= cise@CGU =========\n");
    #ifndef ONSCREEN
    fclose(fp);
    #endif
    return 0;
}

void init_lot(void) {
    for (int i = 0 ; i<MAXLOT ; i++) {
        lot[i]=i+1;
    }
}

void shuf_lot(void) {
    int tmp, k;
    for (int i = MAXLOT-1 ; i>0 ; i--) {
        k = rand() % (i+1);
        swap_lot(i, k);
    }
}

int sp_lot(void) {
    for (int i = NORMAL ; i<MAXLOT ; i++) {
        if (lot[i] <= SPLOT) {
            return lot[i];
        }
    }
    return -1;
}

void sort_lot(void) {
    int tmp;
    for (int i = 0; i<NORMAL ; i++) {
        for (int j = 0 ; j<NORMAL ; j++) {
            if (lot[i] < lot[j]) {
                swap_lot(i, j);
            }
        }
    }
}

void swap_lot(int i, int j) {
   int tmp = lot[i];
   lot[i] = lot[j];
   lot[j] = tmp;
}
