SRC=devlist.c
OBJ=devlist.o
OUT=devlist
CFLAGS=-Wall

$(OUT): $(OBJ) 
	gcc -o $(OUT) $(OBJ) -libverbs

$(OBJ): $(SRC) 
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o $(OUT)
