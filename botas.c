#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE	100
#define ESQ	0
#define DIR	1

#define min(a,b) (((a) < (b)) ? (a) : (b))

//SOLUÇÃO DE https://github.com/alura-cursos/maratonaprogramacao/blob/aula1-exc/BOTAS.cpp

int cnt[70][2];

void limpa() {
	// Zera o numero de botas encontradas em outros testes do problema
	int tam;
	for(tam = 30; tam <= 60; tam++) {
		cnt[tam][ESQ] = 0;
		cnt[tam][DIR] = 0;
	}
}

int tipo(char pe) {
	if(pe == 'E')
		return ESQ;
	else 
		return DIR;
}

int main () {
	FILE *fp;
	fp = freopen("input1.txt", "r", stdin);
	
	char buf[LINE_SIZE];
	memset(buf, 0, LINE_SIZE);
	
	if (fp == NULL) {
		printf("Erro ao abrir arquivo");
		return (-1);
	} else {
		
		while (fgets(buf, LINE_SIZE, fp) != NULL) {
			limpa();
			
			int n = strtol(buf, NULL, 10);
			
			int i = 0;
			for (i = 0; i < n; i++) {
				int tam;
				char pe;
				
				fgets(buf, LINE_SIZE, fp);
				sscanf(buf, "%d %c", &tam, &pe);
				
				cnt[tam][tipo(pe)]++;
			}
			
			int npares = 0;
			int tam;
			for (tam = 30; tam <= 60; tam++) {
				npares += min(cnt[tam][ESQ], cnt[tam][DIR]);
			}
			printf("%d\n", npares);
		}
	}
	
	fclose(fp);

    return (0);
}
