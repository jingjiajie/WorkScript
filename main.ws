int printf(char *, ...)

fac(1) = 1
fac(n) = fac(n-1) * n

max(x, y > x) = y
max(x, y)     = x
max(x, ...y)  = max(x, max(y))

main(){
  max(1,2)
  //printf("fac(10) = %d", fac(10))
}


