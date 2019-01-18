int printf(char *, ...)
char * strcpy(char *, char*)
void * malloc(int)
void free(void *)

char *toPChar(void* p) = p

main(){
  str = malloc(100)
  strcpy(str, "hello")
  printf(str)
  free(str)
}

