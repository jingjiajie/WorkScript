int printf(char *,...)

max(x, y > x) = y
max(x, y)     = x
max(x, ...y)  = max(x, max(y))

fib(1) = 1
fib(2) = 1
fib(x) = fib(x-1) + fib(x-2)

main(){
  //printf("我操真不容易，结果是%d", max(1,3,5,7,9,2,4,6,8,0))
  printf("fib(20) = %d", fib(20))
}

