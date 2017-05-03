#include <iostream>
#include <fstream>
#include <string>

#include "bib.h"

using namespace std;

int main () {
	int * vet;

	vet = frequencia("teste.txt");

	for(int i = 0; i <= 26; i++) {
		cout << vet[i] << " ";
	}

	cout << endl;

	return 0;
}