main(){
   printf("hello")
   print("max: ", 
      max(1,3,5,7,9,2,4,6,8,0))
   print("fib(20): ", fib(20))
}

printf("hello", ...) = printf("world\n")
int printf(char *,...)


print_item(long x)  = printf("%lld", x)
print_item(char *x) = printf(x)
print_item(h, ...t)      = {
  print_item(h)
  print_item(t)
}

print(...x) = print_item(x, "\n")

fib(1) = 1
fib(2) = 1
fib(x) = fib(x-1) + fib(x-2)

max(x, y > x) = y
max(x, y)     = x
max(x, ...y)  = max(x, max(y))