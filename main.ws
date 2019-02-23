int printf(char *,...)
printf(long x)  = printf("%lld", x)
printf(h, ...t)      = {
  printf(h)
  printf(t)
}


// max(x, y > x) = y
// max(x, y)     = x
// max(x, ...y)  = max(x, max(y))

// fib(1) = 1
// fib(2) = 1
// fib(x) = fib(x-1) + fib(x-2)

main(){
   printf("max : %d", 123)
}
