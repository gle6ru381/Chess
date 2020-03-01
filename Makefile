OBJECTS=build/main.o build/board.o build/board_print_plain.o build/board_read.o

chess: main.o board.o board_print_plain.o board_read.o
	gcc $(OBJECTS) -Wall -Werror -o bin/chess

board.o:
	gcc -o build/board.o -c src/board.c 

board_print_plain.o:
	gcc -o build/board_print_plain.o -c src/board_print_plain.c

board_read.o:
	gcc -o build/board_read.o -c src/board_read.c

main.o:
	gcc -o build/main.o -c src/main.c

board: board.o
	gcc $(OBJECTS) -Wall -Werror -o bin/chess

board_print_plain: board_print_plain.o
	gcc $(OBJECTS) -Wall -Werror -o bin/chess

board_read: board_read.o
	gcc $(OBJECTS) -Wall -Werror -o bin/chess

main: main.o
	gcc $(OBJECTS) -Wall -Werror -o bin/chess