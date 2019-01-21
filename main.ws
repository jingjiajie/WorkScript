int printf(char *, ...);
char * strcpy(char *, char*);
void * malloc(int);
void free(void *);

f(long x) = "long"
//char *f(int x) = "int"

main(){
  printf(f(1));
}

