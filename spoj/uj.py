import math
def pow( x, n):
  if n == 0:
   return 1
  else:
   p=int(n/2)
   tmp=int(pow(x,p))
   if n%2==1:
    q=tmp*tmp*x
    return (q)
   else:
    r=tmp*tmp
    return (r)

   
while True:
    a=raw_input()
    b=a.split(' ')
    x=int(b[0])
    y=int(b[1])
    if x == 0 and y == 0:
     break
    if y == 0:
     print 1
     continue
    z=int(pow(x,y))
    print z


    
