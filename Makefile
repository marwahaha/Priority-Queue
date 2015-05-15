all: priority.c
	gcc -g -Wall -o priority priority.c
	  
clean:
	rm -f priority
	rm -f priorityTest

test: priorityTest.c
	gcc -g -Wall -o priorityTest priorityTest.c
