#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define LINE_SIZE	100

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
			
		}
	}
	
	fclose(fp);

    return (0);
}
