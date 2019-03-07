/*
* 程序从main()开始执行，运行4个demo。
* 这4个demo展示了alpha4版本WorkScript所支持的绝大部分语法特性
* 此版本编译器会有非常多的bug。但是一旦您发现了任何一个bug，
* 请一定要反馈到https://github.com/jingjiajie/WorkScript
* 您的反馈会得到最快的回复。
* Have fun.
*/

main()
{
  max_demo()
  fib_demo()
  memory_demo()
  default_arg_demo()
}

memory_demo()
{
  buff = malloc(64)
  strcpy(buff, "hello ")
  strcat(buff, "world")
  print(buff)
  free(buff)
}

max_demo()
{
  print("max(1,3,5,7,9,2,4,6,8,10) = ", max(1,3,5,7,9,2,4,6,8,10))
}

fib_demo()
{
  print("fib(20) = ", fib(20))
}

default_arg_demo()
{
  f()
  f("hello")
}

int printf(char *,...)
void *malloc(unsigned)
void free(void*)
char *strcpy(char*, char*)
char *strcat(char*, char*)

print(...x) = print_item(x, "\n")
print_item(long x)  = printf("%ld", x)
print_item(char *x) = printf(x)
print_item(h, ...t)      = {
  print_item(h)
  print_item(t)
}

f("hello", y := "world") = print(y)
f(x := "hello") = print(x)

fib(1) = 1
fib(2) = 1
fib(x) = fib(x-1) + fib(x-2)

max(x, y > x) = y
max(x, y)     = x
max(x, ...y)  = max(x, max(y))