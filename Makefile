all: btree

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

btree: tree.o btree.o
	cc -o $@ $^

tree.o: tree.c tree.h
	cc -c $(CFLAGS) tree.c

btree.o: btree.c tree.h
	cc -c $(CFLAGS) btree.c

clean:
	rm -f *.o btree

demo: btree
	./btree
