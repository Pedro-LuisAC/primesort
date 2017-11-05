/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int testa_primo(int inteiro){
	int aux_primo;
	if(inteiro == 1){
		return 1;
	}
	else if(inteiro == -1){
		return 0; //por seguranga
	}
	else{
		for(int i = 2; i <= inteiro/2; i++){
			aux_primo = inteiro % i;
			if(aux_primo == 0){
				return 1;
			}
		}
		return 0;
	}
}

int main() {
	int i,aux_primo,leitura,flag_primo;

	FILE *inicia_pipe;

	inicia_pipe = popen("sort -n -r","w");

	if(inicia_pipe == NULL) exit(1); //no tutorial fala para colocar isso mas nao sei pq

			
	while (leitura != -1){
		scanf("%d",&leitura);
		if(leitura == -1){
			goto SAI; //so por seguranca
		}
		else{
		if(testa_primo(leitura)){
			fprintf(inicia_pipe, "%d\n",leitura);
		}
	}
	}
	SAI:
	pclose(inicia_pipe);
	kill(inicia_pipe); //por serguranca
    return(0);
}
