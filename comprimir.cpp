#include "bib.h"

// Comprime arquivo fonte passado, armazenando os valores de frequencia e o arquivo comprimido
bool comprimir(string arqFonte, string arqFreq, string arqComp) {
    // Abre arquivos
    ifstream fonte(arqFonte, ifstream::binary);
    ofstream freq(arqFreq), comp(arqComp, ofstream::binary);

    // Variaveis locais    
    unsigned char atual;
    int * vet = frequencia(fonte);
    string * codigos = gerarCodigo(gerarArvore(vet));

    fonte.close();
    fonte.open(arqFonte);

    // Le entrada
    while(!fonte.eof()) {
		fonte >> noskipws >> atual;

        // Gambiarra
        if (fonte.eof()) {
            break;
        }

        // Escreve codigo relativo ao caractere atual na saida
		if (atual == 32) {
			comp << codigos[26];
		}
		else {
			comp << codigos[atual - 65];	
		}
	}

    // Escreve frequencias em outro arquivo
    for (int i = 0; i < 27; i++) {
        freq << vet[i] << endl;
    }

    fonte.close();
    comp.close();
    freq.close();

    return true;
}