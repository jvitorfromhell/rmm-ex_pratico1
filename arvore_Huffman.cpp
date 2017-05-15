#include "bib.h"

// Gera arvore baseada em vetore de frequencia de caracteres
Nodo * gerarArvore(int * frequencias) {
    vector<string> alfabeto = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"," "};
    
    // Cria fila de prioridade e altera comparador
    auto comp = [](Nodo * n1, Nodo * n2) -> bool { return n1->getFreq() > n2->getFreq(); };
    priority_queue<Nodo *, vector<Nodo *>, decltype(comp)> fila(comp);
    
    // Inicializa com os nodos padroes
    for(int i = 0; i < 27; i++) {
        if(frequencias[i] != 0) {
            fila.push(new Nodo(alfabeto[i], frequencias[i], NULL, NULL));
        }
    }

    // Caso fila vazia, retorna
    if(fila.size() == 0) { return NULL; }

    // Geracao da arvore
    while(fila.size() > 1) {
        Nodo * esq = fila.top();
        fila.pop();
        Nodo * dir = fila.top();
        fila.pop();
        fila.push(new Nodo(esq->getCodigo() + dir->getCodigo(), esq->getFreq() + dir->getFreq(), esq, dir));
    }

    // Retorna ultimo no como raiz
    return fila.top();
}

// Gera os codigos para cada caracterer baseado na arvore
string * gerarCodigo(Nodo * raiz) {
    
    // Gera dicionario vazio
    string * codigos = new string[27];

    for(int i = 0; i < 27; i++) {
        codigos[i] = "";
    }

    // Executa recursivamente
    codigoRecursivo(raiz, codigos);

    // Retorna dicionario
    return codigos;
}

// Caminha pela arvore, povoando dicionario
void codigoRecursivo(Nodo * nodo, string * codigos) {
    // Se nodo sem filhos, retorna
    if(nodo -> getEsq() == NULL) {
        return;
    }
    else {
        // Coloca um 0 nas entradas relativas a todos os caracteres presente no filho da esquerda
        string cod = nodo->getEsq()->getCodigo();

        for (int i = 0; i < cod.length(); i++) {
            if (cod[i] == 32) {
                codigos[26] += "0";
            }
            else {
                codigos[cod[i] - 65] += "0"; 
            }
        }

        // Coloca um 1 nas entradas relativas a todos os caracteres presente no filho da direita
        cod = nodo->getDir()->getCodigo();

        for (int i = 0; i < cod.length(); i++) {
            if (cod[i] == 32) {
                codigos[26] += "1";
            }
            else {
                codigos[cod[i] - 65] += "1";
            }     
        }

    //Chamada recursiva para os seus filhos
    codigoRecursivo(nodo->getEsq(), codigos);
    codigoRecursivo(nodo->getDir(), codigos);
    }
}