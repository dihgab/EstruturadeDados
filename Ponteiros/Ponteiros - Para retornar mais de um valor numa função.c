#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b){
    return a + b;
}

int main(){
    int x,y,z;
    int (*p) (int, int);
    printf("Digite 2 numeros: ");
    scanf("%d %d", &x, &y);
    
    //Ponteiro recebe endereço da função

    p = soma;
    z = p(x,y);
    printf("Soma = %d\n", z);

}