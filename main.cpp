#include "bib.h"

using namespace std;

int main () {
	string entrada("random.bin"), frequencias("freq.bin"), compresso("comp.bin"), restaurado("descomp.bin");
	cout << "Compressao de arquivos de teste utilizando o algoritmo de Huffman" << endl;
	cout << "O arquivo 'random.bin' sera compresso no arquivo 'comp.bin' e restaurado no arquivo 'descomp.bin'" << endl;
	comprimir(entrada, frequencias, compresso);
	cout << "Compressao completa com sucesso" << endl;
	descomprimir(compresso, frequencias, restaurado);
	cout << "Restauro completo com sucesso" << endl;
	return 0;
}