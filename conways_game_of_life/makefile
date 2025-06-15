CC= gcc

OUT = game_of_life_bin

SRC = game_of_life.c

CFLAGS = $(shell sdl2-config --cflags --libs)

$(OUT):	$(SRC) 
			$(CC) $(SRC) -o $(OUT) $(CFLAGS)  


build: $(OUT)

clean:
	rm -f $(OUT)

run: $(OUT)
		./$(OUT)  

