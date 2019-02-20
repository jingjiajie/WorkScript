int printf(char *,...)

max(x, y > x) = y
max(x, y)     = x
max(x, ...y)  = max(x, max(y))

main(){
  printf("我操真不容易，结果是%d", max(1,3,5,7,9,2,4,6,8,0))
}

