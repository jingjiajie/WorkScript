int printf(char *, ...)

//max(x, y > x) = y
//max(x, y)     = x
max(x, ...y)  = max(x, max(y))

main(){
  max(1,2)
}


