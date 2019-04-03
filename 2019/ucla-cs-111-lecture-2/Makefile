.PHONY: all
all: myalloc.so alloc_test hello_world_c atexit_example

myalloc.so: myalloc.o
	gcc myalloc.o -shared -ldl -o $@

myalloc.o: myalloc.c
	gcc -fPIC $< -c

alloc_test: alloc_test.c
	gcc $< -o $@

hello_world_c: hello_world.c
	gcc $< -o $@

atexit_example: atexit_example.c
	gcc $< -o $@

.PHONY: clean
clean:
	rm -f myalloc.o myalloc.so alloc_test hello_world_c atexit_example
