#include <stdio.h>

int ruso(int mult1, int mult2);
int egipcio(int mult1, int mult2);

int main(){
	
	int mul1, mul2, result;
	
	do{
	
		printf("Ingresa el primer numero: ");
		scanf("%d",&mul1);
		printf("Ingresa el segundo numero: ");
		scanf("%d",&mul2);
		
	}while(mul1<0 or mul1>999 or mul2<0 or mul2>999);
	
	printf("\n\n\n-----------METODO RUSO-----------");
	result = ruso(mul1,mul2);
	printf("\n\nEl resultado es: %d",result);
	
	printf("\n\n\n-----------METODO EGIPCIO-----------");
	result = egipcio(mul1,mul2);
	printf("\n\nEl resultado es: %d",result);
	
	return 0;
}

int ruso(int mult1, int mult2){
	int doble=mult1, mitad=mult2, resul=0, i=0, fin=0; 
	int A[20];
	
	printf("\n\tDOBLE\t|\tMITAD\n");
	printf("---------------------------------\n");	
	do{

		if(mitad%2 == 0){
			printf("\t%d\t|\t%d\n",doble,mitad);
			doble *= 2;
			mitad /= 2;	
		}else{
			printf("\t%d\t|\t%d *\n",doble,mitad);
			A[i]=doble;
			i++;
			resul += doble;
			doble *= 2;
			mitad /= 2;	
		}	
		
	}while(mitad>0);
	
	fin = i;
	printf("\n");
	
	for(i=0; i<=fin; i++){
		if(i==fin){
			printf("=%d",resul);
		}else if(i==0){
			printf("%d",A[i]);
		}else{
			printf("+%d",A[i]);
		}
	}
	
	return resul;
}

int egipcio(int mult1, int mult2){
	int doble1=mult1, doble2=1, resul=0, i=1, aux=0, j=0; 
	int A[11], B[11], C[20];
	
	printf("\n\tDOBLE\t|\tDOBLE\n");
	printf("---------------------------------\n");	
	
	A[i]=doble1;
	B[i]=doble2;
	
	do{
		printf("\t%d\t|\t%d\n",A[i],B[i]);
		i++;
		doble1 *= 2;
		doble2 *= 2;
		A[i]=doble1;
		B[i]=doble2;	
		
	}while(doble2<mult2);
	
	printf("\n\n\tDOBLE\t|\tDOBLE\n");
	printf("---------------------------------\n");
	
	i--;
	aux = B[i];
	resul = resul+A[i];
	printf("\n\t%d\t|\t%d\n",A[i],B[i]);
	C[j] = A[i];
	j++;
	i--;
	do{
		if((B[i]+aux)<=mult2){
			printf("\t%d\t|\t%d",A[i],B[i]);
			resul +=  A[i];
			printf("+%d",aux);
			aux += B[i];
			printf("=%d\n",aux);
			C[j] = A[i];
			j++;
		}
		i--;
	}while(i>=0);

	printf("\n");
	
	for(i=0; i<=j; i++){
		if(i==j){
			printf("=%d",resul);
		}else if(i==0){
			printf("%d",C[i]);
		}else{
			printf("+%d",C[i]);
		}
	}
	
	return resul;
}
