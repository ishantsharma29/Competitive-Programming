
t=input()
while t:
 a=raw_input().split(' ')
 x=int(a[0])
 n=int(a[1])
 s=x
 while x>=n:
  s=s+int(x/n)
  p=x
  x=int(x/n)
  if p%n!=0:
    x=x+int(p%n)
 print s
 t=t-1 
    
