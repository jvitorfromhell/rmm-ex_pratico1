#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "bib.h"

using namespace std;

int * frequencia(string nome) {
	int * vet = (int *) malloc(27 * sizeof(int));

	char atual;

	ifstream arq(nome);

	while(!arq.eof()) {
		arq >> noskipws >> atual;

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