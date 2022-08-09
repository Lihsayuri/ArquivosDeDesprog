#include <stdio.h>

// int pow(int b, int e) {
//     if (e == 0){
//         return 1;
//     }
//     // devolve b^e
//     // pow(b, e-1); // devolve b^(e-1)
//     return pow(b, e - 1) * b;
// }

// int soma(int v[], int n) {
//     if (n == 0){
//         return 0; // o meu array tá vazio brother, não tem o que somar. 
//     }

//     printf("%d\n", (v[n-1] + soma(v, n - 1)));
//     return soma(v, n - 1) + v[n-1]; // soma o resultado da chamada da função com o anterior
// }


// void incrementa(int v[], int l, int r) {
//     if (l > r){
//         return;
//     }
//     v[r]++;
//     incrementa(v, l, r - 1);

//     printf("%d\n", v[r]);
// }

// int log2(int n){
//     if (n == 1){
//         return 0;
//     }
//     // recebe uma potência de 2 e devolve o expoente da potência;
//     return log2(n/2)+1;
// }


// int simetrico(int v[], int l, int r){
//     // devolve 1 se v[0] == v[r-1]; v[1] == v[r-2]; v[2] == v[r-3]

//     if (l >=  r){
//         return 1; 
//     }

//     return  v[r] == v[l] && simetrico(v, l+1, r-1);
// }

// double potencia(double b, int e){
//     if (e == 0){
//         return 1;
//         }
//     if (e > 0){
//         return potencia(b, e-1)*b;
//     } if (e < 0){
//         return potencia(b, e+1)*(1/b);
//     }
// }

// int contaDigitos(n){

//     if (n >= 0 && n < 10){
//         return 1;
//     }

//     return contaDigitos(n/10)+1;
// }

void cumulativo (int v[], int n){
    if (n == 1){
        return;
    }   

    cumulativo(v, n-1);
    v[n-1] = v[n-1] + v[n-2];
}

void simetriza(double v[], int l, int r) {
    if (l >= r){
        return;
    }

    simetriza (v, l + 1, r - 1);

    double media;
    media = (v[l] + v[r])/(double) 2;
    v[l] = media;
    v[r] = media;
    printf("%lf\n", v[l]);
    printf("%lf\n", v[r]);
}

void simetriza1(double v[], int l, int r){
    if (l >= r){
        return;
    }

    double media = (v[l] + v[r])/(double) 2;
    v[l] = media;
    v[r] = media;

    simetriza(v, l+1, r-1);
}

void simetriza2(double v[], int l, int r) {
    if (l >= r) {
        return;
    }
    simetriza(v, l + 1, r - 1);
    double m = (v[l] + v[r]) / 2;
    v[l] = m;
    v[r] = m;
    
}

int div(int a, int b) {
    if (a == 0){
        return 0;
    }
    if (a == 1 && a < b){
        return 0;
    }

    return div(a-b, b) + 1;
}

int qtd_pares(int v[], int l, int r) {
    if (l == r){
        return (v[l] % 2 == 0);
    }

    return qtd_pares(v, l, r-1) + (v[r] % 2 == 0);
}


void clip(int v[], int n, int l) {
    if (n == 0){
        return;
    }

    if (v[n-1] > 0){
        if(v[n-1] > l){
            v[n-1] = l;
        }
    } if (v[n-1] < 0){
        if (v[n-1] < -l){
            v[n-1] = -l;
        }
    }

    clip(v, n-1, l);

}


int main(){

    int v[4] = {5, -3, 7, -1};
    clip(v,4,4);

    for (int i = 0; i < 4; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}
