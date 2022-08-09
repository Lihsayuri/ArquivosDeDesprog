#include <math.h>

#define _USE_MATH_DEFINES


#include "fourier.h"


void nft(double complex s[MAX_SIZE], double complex t[MAX_SIZE], int n, int sign) {
    for (int k = 0; k < n; k++) {
        t[k] = 0;
        for (int j = 0; j < n; j++) {
            t[k] += s[j] * cexp(sign * 2 * PI * k * j * I / n);
        }
    }
}

void nft_forward(double complex s[MAX_SIZE], double complex t[MAX_SIZE], int n) {
    nft(s, t, n, -1);
}

void nft_inverse(double complex t[MAX_SIZE], double complex s[MAX_SIZE], int n) {
    nft(t, s, n, 1);
    for (int k = 0; k < n; k++) {
        s[k] /= n;
    }
}

void fft(double complex s[MAX_SIZE], double complex t[MAX_SIZE], int n, int sign) {
    if(n <= 1){  
        t[0] = s[0];
        return;
    }

    double complex s_even[n/2];
    double complex s_odd[n/2];
    double complex t_even[n/2];  
    double complex t_odd[n/2];  
    
    for (int i = 0; i < n/2; i+=1){
        s_even[i] = s[i*2];
        s_odd[i] = s[1+i*2];
    }

    fft(s_even, t_even, n/2, sign);
    fft(s_odd, t_odd, n/2, sign);

    for(int k = 0; k < (n/2); k++){
        t[k] = t_even[k] + t_odd[k]*cexp(sign*2*PI*(k)*I/n);
        t[k+n/2] = t_even[k] - t_odd[k]*cexp(sign*2*PI*(k)*I/n);
    }
}

void fft_forward(double complex s[MAX_SIZE], double complex t[MAX_SIZE], int n) {
    fft(s, t, n, -1);
}

void fft_inverse(double complex t[MAX_SIZE], double complex s[MAX_SIZE], int n) {
    fft(t, s, n, 1);
    for (int k = 0; k < n; k++) {
        s[k] /= n;
    }
}

void fft_forward_2d(double complex matrix[MAX_SIZE][MAX_SIZE], int width, int height) {
    double complex mat_col_input[MAX_SIZE];

    double complex t_row_exit[MAX_SIZE];
    double complex t_col_exit[MAX_SIZE];

    // para o caso da linha. Para cada linha a fft_forward é aplicada. Depois a saída dela, que não é um retorno, é passada para a matriz original.
    for (int col = 0; col < height; col++){
        fft_forward(matrix[col], t_row_exit, width);
        for (int row = 0; row < width; row++){
            matrix[col][row] = t_row_exit[row];
        }
    }

    // para o caso da coluna. Para cada coluna primeiro preenchemos a variável de entrada para a fft_forward. E depois passamos a saída para a matriz original.
    for (int row = 0; row < width; row++){
        for (int col = 0; col < height; col++){
            mat_col_input[col] = matrix[col][row]; 
        }  
        fft_forward(mat_col_input, t_col_exit, height);
        for (int col = 0; col < height; col++){
           matrix[col][row] = t_col_exit[col]; 
        }
    }
    
}

void fft_inverse_2d(double complex matrix[MAX_SIZE][MAX_SIZE], int width, int height) {
    double complex mat_col_input[MAX_SIZE];

    double complex t_row_exit[MAX_SIZE];
    double complex t_col_exit[MAX_SIZE];

    // para o caso da linha. Para cada linha a transformada inversa de Fourier é aplicada. Depois a saída dela, que não é um retorno, é passada para a matriz original.
    for (int col = 0; col < height; col++){
        fft_inverse(matrix[col], t_row_exit, width);
        for (int row = 0; row < width; row++){
            matrix[col][row] = t_row_exit[row];
        }
    }

    // para o caso da coluna. Para cada coluna primeiro preenchemos a variável de entrada para a função inversa de Fourier. Depois, a saída é passada para a matriz original. 
    for (int row = 0; row < width; row++){
        for (int col = 0; col < height; col++){
            mat_col_input[col] = matrix[col][row]; 
        }  
        fft_inverse(mat_col_input, t_col_exit, height);
        for (int col = 0; col < height; col++){
           matrix[col][row] = t_col_exit[col]; 
        }
    }  

}

void filter(double complex input[MAX_SIZE][MAX_SIZE], double complex output[MAX_SIZE][MAX_SIZE], int width, int height, int flip) {
    int center_x = width / 2;
    int center_y = height / 2;
    double variance = -2 * SIGMA * SIGMA;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = center_x - (x + center_x) % width;
            int dy = center_y - (y + center_y) % height;
            double d = dx * dx + dy * dy;
            double g = exp(d / variance);
            if (flip) {
                g = 1 - g;
            }
            output[y][x] = g * input[y][x];
        }
    }
}

void filter_lp(double complex input[MAX_SIZE][MAX_SIZE], double complex output[MAX_SIZE][MAX_SIZE], int width, int height) {
    filter(input, output, width, height, 0);
}

void filter_hp(double complex input[MAX_SIZE][MAX_SIZE], double complex output[MAX_SIZE][MAX_SIZE], int width, int height) {
    filter(input, output, width, height, 1);
}