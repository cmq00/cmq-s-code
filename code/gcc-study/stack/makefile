all : libstack.so stack_exp_so stack_struct stack_bin

libstack.so:stack.c stack.h
	gcc stack.c -fPIC  -c stack.c  
	gcc -shared stack.o -o libstack.so

stack_exp_so:stack_exp_so.c
	gcc stack_exp_so.c -L./ -lstack -o stack_exp_so

stack_struct:stack_struct.c
	gcc stack_struct.c -L./ -lstack -o stack_struct
stack_bin:stack_bin.c
	gcc stack_bin.c -L./ -lstack -o stack_bin
clean:
	rm -rf libstack.so stack_exp_so stack_struct stack_bin
