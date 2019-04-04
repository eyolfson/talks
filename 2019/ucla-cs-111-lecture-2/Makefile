.PHONY: all
all: myalloc.so alloc_test hello_world_c atexit_example libpoint_v1/libpoint.so libpoint_v2/libpoint.so my_code_compiled_with_point_v1 my_code_compiled_with_point_v2

.PHONY: run_my_code_compiled_with_point_v1_with_point_v1
run_my_code_compiled_with_point_v1_with_point_v1:
	LD_LIBRARY_PATH=libpoint_v1 ./my_code_compiled_with_point_v1

.PHONY: run_my_code_compiled_with_point_v1_with_point_v2
run_my_code_compiled_with_point_v1_with_point_v2:
	LD_LIBRARY_PATH=libpoint_v2 ./my_code_compiled_with_point_v1

.PHONY: run_my_code_compiled_with_point_v2_with_point_v1
run_my_code_compiled_with_point_v2_with_point_v1:
	LD_LIBRARY_PATH=libpoint_v1 ./my_code_compiled_with_point_v2

.PHONY: run_my_code_compiled_with_point_v2_with_point_v2
run_my_code_compiled_with_point_v2_with_point_v2:
	LD_LIBRARY_PATH=libpoint_v2 ./my_code_compiled_with_point_v2

my_code_compiled_with_point_v1: my_code.c
	gcc $< -Ilibpoint_v1 -Llibpoint_v1 -lpoint -o $@

my_code_compiled_with_point_v2: my_code.c
	gcc $< -Ilibpoint_v2 -Llibpoint_v2 -lpoint -o $@

libpoint_v1/libpoint.so: libpoint_v1/libpoint.o
	gcc $< -shared -o $@

libpoint_v1/libpoint.o: libpoint_v1/libpoint.c
	gcc -fPIC $< -c -o $@

libpoint_v2/libpoint.so: libpoint_v2/libpoint.o
	gcc $< -shared -o $@

libpoint_v2/libpoint.o: libpoint_v2/libpoint.c
	gcc -fPIC $< -c -o $@

myalloc.so: myalloc.o
	gcc $< -shared -ldl -o $@

myalloc.o: myalloc.c
	gcc -fPIC $< -c -o $@

alloc_test: alloc_test.c
	gcc $< -o $@

hello_world_c: hello_world.c
	gcc $< -o $@

atexit_example: atexit_example.c
	gcc $< -o $@

.PHONY: clean
clean:
	rm -f myalloc.o myalloc.so alloc_test hello_world_c atexit_example libpoint_v1/libpoint.o libpoint_v1/libpoint.so libpoint_v2/libpoint.o libpoint_v2/libpoint.so my_code_compiled_with_point_v1 my_code_compiled_with_point_v2
