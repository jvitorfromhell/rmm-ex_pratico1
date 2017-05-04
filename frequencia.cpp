#include "bib.h"

using namespace std;

// Retorna o numero de ocorrencias de cada simbolo no arquivo
int * frequencia(ifstream & arq) {
	// Variaveis locais
	char atual;
	int * vet = new int[27];

	// Leitura do arquivo
	while(!arq.eof()) {
		// Le caractere atual
		arq >> noskipws >> atual;

		// Incrementa indice relativo
		if (atual == 32) {
			vet[26]++;
		}
		else {
			atual -= 65;
			vet[atual]++;	
		}
	}

	return vet;
}