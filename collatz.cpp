#include <stdio.h>
int main ()
{
    int i, num;
    printf("Ingresa un numero: ");
    scanf("%d",&num);
    printf("\nResultado: ");

    while(num!=1){
        if(num%2 == 0)
            num = num/2;
        else
            num = num*3+1;
        printf("%d", num);
    }
    
    return 0;
}



