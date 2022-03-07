#include <stdio.h>
#include <math.h>

	int main (){
	
	float l1, l2, l3, area;
	
	printf("Insira o valor do primeiro lado: ");
	scanf("%f", &l1);
	printf("Insira o valor do segundo lado: ");
	scanf("%f", &l2);
	printf("Insira o valor do terceiro lado: ");
	scanf("%f", &l3);
	
	
	if(l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1){//checar valor do triangulo
		
		printf("Medidas dos lados formam um triangulo VALIDO\n");
		if(l1 != l2 && l1 != l3 && l2 != l3){//checar se é escaleno
			printf("Classificacao em funcao dos lados: ESCALENO\n");
		} else if(l1 == l2 && l1 == l3 && l2 == l3){//checar se é equilatero
			printf("Classificacao em funcao dos lados: EQUILATERO\n");
		}else{
			printf("Classificacao em funcao dos lados: ISOSCELES\n");
		}
		
		if(pow(l1,2) == pow(l2,2) + pow(l3,2) || pow(l2,2) == pow(l1, 2) + pow(l3,2) || pow(l3,2) == pow(l2,2) + pow(l1,2)){//TESTA SE É RETO
			printf("Classificacao em funcao dos angulos: RETO\n");
		}
		else if( pow(l1,2) > pow(l2,2) + pow(l3,2) || pow(l2,2) > pow(l1, 2) + pow(l3,2) || pow(l3,2) > pow(l2,2) + pow(l1,2)){//TESTA SE É OBTUSO
		printf("Classificacao em funcao dos angulos: OBTUSO\n");}
		else{
			printf("Classificacao em funcao dos angulos: AGUDO\n");
		}
//		if(pow(l1,2) == pow(l2,2) + pow(l3,2)){//area de um triangulo retangulo
//			double area = (l2 * l3)/2;
//			printf("Area do triangulo: %f", area);
//		} else if(pow(l2,2) == pow(l1, 2) + pow(l3,2) ){
//			area = (l1 * l3)/2;
//			printf("Area do triangulo: %f", area);
//			
//		} else if(pow(l3,2) == pow(l2,2) + pow(l1,2)){
//			area = (l2 * l1)/2;
//			printf("Area do triangulo: %f", area);
//		}
//		else if(l1 == l2 && l1 == l3 && l2 == l3){//area de um triangulo equilatero
//			area = (sqrt(3)/4) * pow(l1,2);
//		}
//		else if(l1 == l2 && )
//	
		double sPer = (l1 + l2 + l3)/2;
		double area = sqrt(sPer*(sPer - l1)*(sPer - l2)*(sPer - l3));
		printf("Area do triangulo: %g", area);
		
		
		
	} else {//NÃO é um triangulo valido
		
		printf("Medidas dos lados formam um triangulo INVALIDO\n");
		
	}
	
	
	
	
	return 0;
	
	}