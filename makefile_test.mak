OPTS = -g -Wall -std=c11

t9.o: t9.c trie.h
	gcc $(OPTS) -c trie.c

t9: t9.o trie.o
	gcc $(OPTS) -o t9 t9.o trie.o

trie.o: trie.c trie.h
	gcc $(OPTS) -c t9.c

clean:
	rm *.o output