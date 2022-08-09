#include <math.h>

#include "geometry.h"


double teste_com_x_na_eq_reta (point p1, point p2, int y){
    double m;
    double x;
    m = ((p2.y - p1.y)/ (double)(p2.x - p1.x));
    x = ((y + m*p1.x - p1.y)/ (double) m);
    return x;
}


int casos_aresta_horizontal(point p, point a, point b){
    int maior_x;   
    int menor_x;

    if (a.x > b.x){
        maior_x = a.x;
        menor_x = b.x;
    } else {
        maior_x = b.x;
        menor_x = a.x;
    }

    // nesse caso o raio nunca irá cruzar a reta. Já que o ponto ou estará na própria reta, ou será o caso especial em que ao girar para a direita, não
    // irá cruzar. 

    if ((p.y == a.y) && (p.x <= maior_x) && (p.x >= menor_x) ){ // para quando px está em algum ponto da reta (incluindo a.x e b.x)
        return 2;
    }
    else if ((p.y == a.y) && (p.x < menor_x)){  //caso especial em que p.x está antes da linha horizontal e que ao virar o raio à direita, não irá cruzar.
        return 0;
    }
    return 0; 

}

int casos_aresta_vertical(point p, point a, point b){
    int maior_y;
    int menor_y;

    if (a.y > b.y){
        maior_y = a.y;
        menor_y = b.y;
    } else {
        maior_y = b.y;
        menor_y = a.y;
    }

    if ((p.x == a.x) && (p.y <= maior_y) && (p.y >= menor_y) ){ // para quando py está em algum ponto da reta (incluindo a.y e b.y)
        return 2;
        }
    else if (p.x < a.x && p.y <= maior_y && p.y > menor_y){ // quando o ponto está antes da vertical e cruza ela.
        return 1;                                          // isso já inclui o caso especial: quando estiver na mesma altura do ymaior e antes do x da reta
    }                                                      // viro  raio a direita e pega. Mas quando estiver no ymenor, viro a direita e não pega

    return 0; 

}

int casos_aresta_diagonal(point p, point a, point b){
    double x_na_reta; 
    x_na_reta = teste_com_x_na_eq_reta(a, b, p.y);
    int maior_y;
    int menor_y;
        
    if (a.y > b.y){
        maior_y = a.y;
        menor_y = b.y;
    } 
    
    else{
        maior_y = b.y;
        menor_y = a.y;
    }

    if ((p.x < x_na_reta) && (p.y <= maior_y && p.y > menor_y)){ //quando o ponto passa a diagonal. Isso inclui os casos especiais de quando    
        return 1;                                           // precisa virar a direita considerando se py == maior_y e quando precisa virar a direita 
    }                                                       // considerando py == menor_y.
    
    else if((x_na_reta == p.x) && (p.y <= maior_y && p.y >= menor_y)){ //quando o ponto está na diagonal (incluindo maior_y e menor_y)
        return 2;                                                   
    } 
    

    return 0;
}


int verify(point p, point a, point b) {    

    if (a.y == b.y){ 
       return casos_aresta_horizontal(p, a, b);
    }

    else if(a.x == b.x){      
        return casos_aresta_vertical(p, a, b);
    }

    else{ 
        return casos_aresta_diagonal(p, a, b);
    }
}


int inside(point p, point poly[], int n) {
    int soma_resultados = 0;
    for (int i = 0; i <= n-1; i++){
        int resultado;        
   
        if (i == n-1){
            resultado = verify(p, poly[n-1], poly[0]);

        } else{
            resultado = verify(p, poly[i], poly[i+1]);

        }

        if (resultado == 2){
            return 1;
        }

        soma_resultados+= resultado;

    }

    if (soma_resultados % 2 != 0){
        return 1;
    } 
    return 0;
}