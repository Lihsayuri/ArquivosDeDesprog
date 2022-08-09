#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t) {
    if (fscanf(file, "%d", p) != 1) {
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do {
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
    // se n == 0 ou m == 0, então length[n][m] = 0. 
    if(n == 0 || m == 0){
        length[n][m] = 0;
        return 0;
    }
    if(length[n][m] == -1){
        length[n][m] = 0;
        // se a[n-1] == b[m-1], então length[n][m] = length[n-1][m-1] + 1;
        if(a[n-1] == b[m-1]){
            int ret1 = mlcs_w(a, n-1, b, m-1, length) + 1;
            length[n][m] = length[n-1][m-1] + 1;
            return ret1;
        }
        else{
            //senão length[n][m] = max(length[n-1][m], length[n][m-1])
            int ret2 = mlcs_w(a, n-1, b, m, length);
            int ret3 = mlcs_w(a, n, b, m-1, length);
            if(ret2 > ret3){
                length[n][m] = ret2;
                return ret2;
            }
            else{
                length[n][m] = ret3;
                return ret3;
            }
        }
    }
    return length[n][m];
}

int mlcs(char a[], int n, char b[], int m) {    
    int length[MAX_SIZE + 1][MAX_SIZE + 1];
    for(int i=1; i <= n; i++){
        for(int j=1; j <= m; j++){
            length[i][j] = -1;
        }
    }
    return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m) {
    int length[n + 1][m + 1];
    for(int i=0; i <= n; i++){
        for(int j=0; j <= m; j++){
            if (i == 0 || j == 0){
                length[i][j] = 0;
            }
            else{
                if(a[i-1] == b[j-1]){
                    length[i][j] = length[i-1][j-1] + 1;
                }
                else{
                    if(length[i-1][j] > length[i][j-1]){
                        length[i][j] = length[i-1][j];
                    }
                    else{
                        length[i][j] = length[i][j-1];
                    }
                }
            }  
        }
    }
    return length[n][m];
}