DIR=../build/

FLAGS=-Wall -Werror -Wextra -std=c11 

all: graph_program

test: test_build

graph_program: graph.o main.o stack.o calculator.o type.o translate.o
	gcc $(FLAGS) graph.o main.o stack.o calculator.o type.o translate.o -o $(DIR)graph && make clean_temp

test_build: graph.o main.o stack.o calculator.o type.o translate.o
	gcc $(FLAGS) graph.o main.o stack.o calculator.o type.o translate.o -o graph && make clean_temp

calculator.o: calculator.c
	gcc $(FLAGS) -c calculator.c -o calculator.o

translate.o: translate.c
	gcc $(FLAGS) -c translate.c -o translate.o

type.o: type.c
	gcc $(FLAGS) -c type.c -o type.o

graph.o: graph.c
	gcc $(FLAGS) -c graph.c -o graph.o

main.o: main.c
	gcc $(FLAGS) -c main.c -o main.o

stack.o: stack.c 
	gcc $(FLAGS) -c stack.c -o stack.o

clean:  
	rm -f *.o $(DIR)/*

clean_temp:  
	rm -f *.o

rebuild: clean all