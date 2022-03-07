#include <stdio.h>
int main() {
    double x, y, n, e, k, m;
    //x = sqrt,  n =  numero, e = precisão, k = contador, m = modulo..
    k=0;
    
    printf("Digite o valor da raiz n: ");
    if( scanf("%lf", &n) == 0 ) { //conferindo valor double
        printf("\n erro. Valor double nao encontrado.\n\n");
        return -1;
    }
    else if(n<0) { // conferindo valor de n
        printf("Valor invalido.");
        return -1;
    }
    printf("Digite o valor da precisao: ");
    if( scanf("%lf", &e) == 0 ) {
        printf("\n erro. Valor double não encontrado.\n\n");
        return -1;
    }

    else if(e<=0) {
        printf("Valor invalido.");
        return -1;
    }
    x = n / 2;
		y = n;
		k = 0;
	while((x * x) - n > e || (x * x) - n < -e ){
	
		
		if((x * x) > n){// entre 0 e x
			y = x;
			x = y / 2;
		
			k++;
		}
		 if((x * x) < n) {// entre x e y;
			x = y + (x / 2);
		
			k++;
		}
		
	}
	if((x * x) - n < 0){
	m = ((x * x) - n) * -1;
	}
	else{
		m = (x * x) - n;
	}
	
	if(m <= e){//resultado

	
	//printf("O valor da raiz de %g com precisao %g = %g\n\n ", n, e, x);
	printf("Numero de iteracoes: %g\n\n", k);
	printf("Diferenca absoluta: %g\n\n", m);
	printf("Raiz quadrada: %g\n\n", x);
	getchar();
	}
	
	getchar();
	return 0;
	}