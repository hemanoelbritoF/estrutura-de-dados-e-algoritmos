Bib: main.o BibArquivos.o
	gcc  -o  tp1.out main.o BibArquivos.o -g -lm
main.o: main.c BibArquivos.h 
	gcc  -g -c main.c
BibArquivos.o: BibArquivos.c BibArquivos.h
	gcc  -g -c BibArquivos.c  -lm  
clean:	
	rm -f *.o tp1.out *.txt