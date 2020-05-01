import math
def pow ( x , n ) :
 aux = 1
 while n > 1 :
  if n & 1 : #odd
   aux *= x
  x*=x
  n =int (n/2)
 return x*aux



2nd method

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

