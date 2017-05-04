#include "bib.h"

using namespace std;

int main () {
	int * vet;

	ifstream arq("teste.txt");

	if(arq.is_open()) {
		vet = frequencia(arq);

		for(int i = 0; i <= 26; i++) {
			cout << vet[i] << " ";
		}

		cout << endl;
	}

	return 0;
}