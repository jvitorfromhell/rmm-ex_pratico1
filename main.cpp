#include "bib.h"

using namespace std;

int main () {
	int * vet;

	ifstream arq("teste.txt");

	if(arq.is_open()) {
		string * codigos = gerarCodigo(gerarArvore(frequencia(arq)));
		
		for (int i = 0; i < 27; i++)
			cout << codigos[i] << endl;

	}

	return 0;
}