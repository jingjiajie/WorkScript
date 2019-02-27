f(x := "I'm default arg", y := 123, ...) = print(y)
f(x := "I'm default arg", ...) = print(x)

main()
{
   f()
   print(max(100,5,856,23,-6,2))
   print(fib(20))
}

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