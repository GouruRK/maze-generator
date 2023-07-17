CC=gcc
CFLAGS=-Wall -std=c17 -pedantic -I include/
OBJ=graphic.o generation.o union_find.o main.o
LDLIBS=-lMLV
EXEC=maze

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

union_find.o: src/union_find.c 
	$(CC) $(CFLAGS) -c -o $@ $<

graphic.o: src/graphic.c
	$(CC) $(CFLAGS) -c -o $@ $<

generation.o: src/generation.c
	$(CC) $(CFLAGS) -c -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
