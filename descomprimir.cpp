#include "bib.h"

bool descomprimir(string arqFonte, string arqFreq, string arqDesc) {
    // Abre arquivos
    ifstream fonte(arqFonte, ifstream::binary), freq(arqFreq);
    ofstream desc(arqDesc, ifstream::binary);

    // Variaveis locais
    bitset<1> atual;
    int * vet = new int[27];
    Nodo * raiz, * nodoAtual;

    // Le arquivo de frequencias e gera vetor
    for (int i = 0; i < 27; i++) {
        freq >> vet[i];
    }

    // Gera arvore e decodifica entrada
    raiz = gerarArvore(vet), * nodoAtual;
    while(!fonte.eof()) {
        nodoAtual = raiz;

        while(nodoAtual->getCodigo().length() != 1) {
            fonte >> atual;
            
            if (atual[0]) {
                nodoAtual = nodoAtual->getDir();
            }
            else {
                nodoAtual = nodoAtual->getEsq();
            }
        }

        if (fonte.eof()) {
            break;
        }

        desc << nodoAtual->getCodigo();
    }

    return true;
}