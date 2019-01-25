int printf(char *, ...);
char * strcpy(char *, char*);
void * malloc(int);
void free(void *);

f(unsigned long x) = "long"
f(int x) = "int"

main(){
  printf(f(123));
}

