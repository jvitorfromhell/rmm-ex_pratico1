#include "bib.h"

bool comprimir(string arqFonte, string arqCodigo, string arqComp) {
    ifstream fonte(arqFonte);
    ofstream cod(arqCodigo), comp(arqComp);
    
    string * codigos = gerarCodigo(gerarArvore(frequencia(fonte)));

    for (int i = 0; i < 27; i++) {
        if (codigos[i] != "") {
            if(i == 26) {
                arqCodigo << "  " << codigos[i] << endl;
            }
            else {
                arqCodigo << 
            }
        }
    }

    return true;
}