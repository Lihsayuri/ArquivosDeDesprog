#include <stdio.h>

// para todo i de n-1 a 1
//     trocou = 0

//     para todo j de 0 a i-1
//         se v[j] > v[j + 1]
//             troca v[j] e v[j + 1]
//             trocou = 1

//     se não trocou
//         interrompe o loop



void bubble_sort(int v[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int trocou = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                trocou = 1;
            }
     
        }
        if (!trocou){
            break;
        }
    }
}


// para todo i de 0 a n-2
//     seja m o índice do menor elemento entre i e n-1
//     troca v[m] e v[i]

// {7,1,4,3,9,3,2} 0 ate 5


void selection_sort(int v[], int n){
    for (int i = 0; i < n-1; i++){
        int indice_menor_valor = i;
        for (int j; j < n; j++){
            if (v[indice_menor_valor] > v[j]){
                indice_menor_valor = j;
            }
        }

        if (indice_menor_valor != i){
            int temp = v[indice_menor_valor];
            v[indice_menor_valor] = v[i];
            v[i] = temp;
        }


    }


}

void insert_sort(int v[], int n){
    for (int i = 1; i < n; i++) {          // para todo i de 1 a n-1
        int temp = v[i];                   //     temp = v[i]
        int j = i;                         //     encontre um índice j
        while (j > 0 && v[j - 1] > temp) { //     entre 0 e i-1 para
            j--;     
            v[j] = v[j - 1];               
        }                                             
        v[j] = temp;                       
    }
}


int main()
{
    int vec[5] = {4, 5, 2, 3, 1};

    bubble_sort(vec, 5);

    for (int i = 0; i < 5; i++){
        printf("%d ", vec[i]);
    }

    return 0;
}


int particiona(int v[], int l, int r) {
    int p = l;

    for (int i = l; i < r; i++) {
        if (v[i] < v[r]) {
            if (p != i) {
                troca(v, p, i);
            }
            p++;
        }
    }

    if (p != r) {
        troca(v, p, r);
    }

    return p;
}

void quick_sort_r(int v[], int l, int r) {
    if (l >= r) {
        return;
    }
    int p = particiona(v, l, r);
    quick_sort_r(v, l, p - 1);
    quick_sort_r(v, p + 1, r);
}

void quick_sort(int v[], int n) {
    quick_sort_r(v, 0, n - 1);
}


