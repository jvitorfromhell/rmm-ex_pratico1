#include "bib.h"

Nodo * gerarArvore(int * frequencias) {
    vector<string> alfabeto = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"," "};
    
    auto comp = [](Nodo * n1, Nodo * n2) -> bool { return n1->getFreq() > n2->getFreq(); };
    priority_queue<Nodo *, vector<Nodo *>, decltype(comp)> fila(comp);
    
    for(int i = 0; i < 27; i++) {
        if(frequencias[i] != 0) {
            fila.push(new Nodo(alfabeto[i], frequencias[i], NULL, NULL));
        }
    }

    if(fila.size() == 0) { return NULL; }

    while(fila.size() > 1) {
        Nodo * esq = fila.top();
        fila.pop();
        Nodo * dir = fila.top();
        fila.pop();
        fila.push(new Nodo(esq->getCodigo() + dir->getCodigo(), esq->getFreq() + dir->getFreq(), esq, dir));
    }

    return fila.top();
}

string * gerarCodigo(Nodo * raiz) {
    string * codigos = new string[27];

    for(int i = 0; i < 27; i++) {
        codigos[i] = "";
    }

    codigoRecursivo(raiz, codigos);

    return codigos;
}

void codigoRecursivo(Nodo * nodo, string * codigos) {
    if(nodo -> getEsq() == NULL) {
        return;
    }
    else {
        
        string cod = nodo->getEsq()->getCodigo();

        for (int i = 0; i < cod.length(); i++) {
            if (cod[i] == 32) {
                codigos[26] += "0";
            }
            else {
                codigos[cod[i] - 65] += "0"; 
            }
        }

        cod = nodo->getDir()->getCodigo();

        for (int i = 0; i < cod.length(); i++) {
            if (cod[i] == 32) {
                codigos[26] += "1";
            }
            else {
                codigos[cod[i] - 65] += "1";
            }     
        }
    codigoRecursivo(nodo->getEsq(), codigos);
    codigoRecursivo(nodo->getDir(), codigos);
    }
}