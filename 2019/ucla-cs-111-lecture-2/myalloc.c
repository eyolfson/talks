#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>

void *
malloc(size_t size)
{
  void* (*malloc_ptr)(size_t);
  *(void**) (&malloc_ptr) = dlsym(RTLD_NEXT, "malloc");
  void *ret = (*malloc_ptr)(size);

  char buf[200];
  int buf_size = sprintf(buf, "Call to malloc(%lu) = %p\n", size, ret);
  write(1, buf, buf_size);

  return ret;
}

void
free(void *ptr)
{
  void (*free_ptr)(void *);
  *(void**) (&free_ptr) = dlsym(RTLD_NEXT, "free");
  (*free_ptr)(ptr);

  char buf[200];
  int buf_size = sprintf(buf, "Call to free(%p)\n", ptr);
  write(1, buf, buf_size);
}
