compila:
	g++ -o huffman frequencia.cpp arvore_Huffman.cpp comprimir.cpp descomprimir.cpp main.cpp -std=c++11

executa:
	./huffman
	diff random.bin descomp.bin

limpa:
	rm huffman
	rm freq.bin
	rm comp.bin
	rm descomp.bin