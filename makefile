OPTS = -g -Wall -std=c11

t9: t9.o trie.o
	gcc $(OPTS) -g -o t9 t9.o trie.o

t9.o: trie.h t9.c
	gcc $(OPTS) -g -c t9.c

trie.o: trie.h trie.c
	gcc $(OPTS) -g -c trie.c

clean:
	rm *.o t9