int printf(char *,...)

// print(long x)  = printf("%lld", x)
// print(char *x)      = printf("%s",x)
// print(h, ...t)      = {
//   print(h)
//   print(t)
// }

// max(x, y > x) = y
// max(x, y)     = x
// max(x, ...y)  = max(x, max(y))

// fib(1) = 1
// fib(2) = 1
// fib(x) = fib(x-1) + fib(x-2)

main(){
  // print("fib(20) = ", fib(20))
  //print("max : ", max(1,3,5,7,9,2,4,6,8,0))
  printf("%s", "a")
  printf("%d", 1)
  printf("%d", 2.0)
}
