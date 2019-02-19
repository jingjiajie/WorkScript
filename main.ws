//int printf(char *,...)

max(x, y > x) = y
max(x, y)     = x
max(x, ...y)  = max(x, max(y))

main(){
  //printf("%d", max(3,5,1))
  max(1,3,5,7)
}

