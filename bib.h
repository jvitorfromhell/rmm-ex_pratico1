#ifndef BIB
#define BIB

#include <iostream>
#include <queue>
#include <fstream>
#include <bitset>

using namespace std;

class Nodo {
    private:
        Nodo *esq, *dir;
        string codigo;
        int freq;

    public:
        Nodo(string s, int i, Nodo * n1, Nodo * n2) : codigo(s), freq(i), esq(n1), dir(n2) {}

        Nodo * getEsq() { return esq; }
        Nodo * getDir() { return dir; }
        int getFreq() { return freq; }
        string getCodigo() { return codigo; }
};

int * frequencia(ifstream & arq);
Nodo * gerarArvore(int * frequencias);
string * gerarCodigo(Nodo * raiz);
void codigoRecursivo(Nodo * nodo, string * codigos);
void salvarCodigo(string arq, string * codigos);
bool comprimir(string arqFonte, string arqFreq, string arqComp);
bool descomprimir(string arqFonte, string arqFreq, string arqDesc);

#endif