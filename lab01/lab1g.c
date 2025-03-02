#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tabulate.h"

#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

void tabulate(int r, int c, char **headers, long long int **data);
void tabulate_sep(int r, int c, char **headers, long long int **data, char sep);
int digit_counter(long long int n);

int digit_counter(long long int n){
    if (n == 0){
        return 1;
    }
    else{
        int digits = 0;
        while (n){
            digits++;
            n /= 10;
        }
        return digits;
    }
}

void tabulate_sep(int r, int c, char **headers, long long int **data, char sep){
    int max_ints[c];

    for (int i = 0; i < c; i++){
        max_ints[i] = 0;
    }
    
    
    for (int i = 0; i < c; i++){
        for (int j = 0; j < r; j++){

            max_ints[i] = max(max_ints[i], digit_counter(data[j][i]));
            
        }
        max_ints[i] = max(max_ints[i], strlen((headers[i])));
    }
    

    for (int i = 0; i < c; i++){
        printf("%c ", sep);
        for (unsigned int k = 0; k < (max_ints[i] - strlen(headers[i])); k++){
            printf(" ");
        }
        printf("%s", headers[i]);
        printf(" ");
    }
    printf("%c\n", sep);
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%c ", sep);
            for (int k = 0; k < (max_ints[j] - digit_counter(data[i][j])); k++){
                printf(" ");
            }
            printf("%lld", data[i][j]);
            printf(" ");
        }
    
    printf("%c\n", sep);
        
    }
}

void tabulate(int r, int c, char **headers, long long int **data){
    tabulate_sep(r, c, headers, data, '|');
}