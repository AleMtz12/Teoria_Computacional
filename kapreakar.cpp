#include <stdio.h>
#include <stdlib.h>

int asNum(int num){
    int digitos[4];
    for (int i=0; i<4; i++){
        digitos[i]=num%10;
        num/=10;
    }

    for (int i=0; i<3; i++){
        for (int j=i+1; j<4; j++) {
            if (digitos[i] > digitos[j]){
                int temp = digitos[i];
                digitos[i] = digitos[j];
                digitos[j] = temp;
            }
        }
    }

    int numeroAs=0;
    for (int i = 0; i < 4; i++){
        numeroAs=numeroAs * 10 + digitos[i];
    }

    return numeroAs;
}

int desNum(int num){
    int digitos[4];
    for (int i=0; i<4; i++){
        digitos[i]=num%10;
        num/=10;
    }

    for (int i=0; i<3; i++){
        for (int j=i+1; j<4; j++){
            if (digitos[i] < digitos[j]){
                int temp = digitos[i];
                digitos[i] = digitos[j];
                digitos[j] = temp;
            }
        }
    }

    int numeroDes=0;
    for (int i=0; i <4; i++){
        numeroDes=numeroDes * 10 + digitos[i];
    }

    return numeroDes;
}

int kaprekar(int numero){
    if (numero == 6174){
        return 0;
    }

    int contador = 0;
    while (numero != 6174) {
        int ascendente = asNum(numero);
        int descendente = desNum(numero);

        numero = descendente - ascendente;
        contador++;
    }

    return contador;
}

int main(){
    int num;

    printf("Ingresa un numero entero de cuatro digitos: ");
    scanf("%d", &num);

    if (num < 1000 || num > 9999) {
        printf("Ingresa un numero de cuatro digitos valido.\n");
        return 1;
    }

    int pasos=kaprekar(num);

    printf("La constante de Kaprekar para %d es %d.\n", num, pasos);

    return 0;
}
