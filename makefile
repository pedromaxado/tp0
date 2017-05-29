CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c99 -march=native -O3

RM = rm -f

VPATH = src

OBJS = main.o rpn.o vector.o stack.o solver.o

MAIN = tp0

$(MAIN): $(OBJS)
	@echo ""
	@echo " --- COMPILANDO PROGRAMA ---"
	@$(CC) $(CFLAGS) $(OBJS) -o $(MAIN)
	@echo ""

%.o: %.c %.h
	@echo " --- COMPILANDO OBJETO \"$@\""
	@$(CC) $(CFLAGS) $< -c

clean:
	$(RM) *.o
	clear

run: $(MAIN)
	./$(MAIN)
