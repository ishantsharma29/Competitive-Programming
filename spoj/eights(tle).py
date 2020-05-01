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

n=input()
while n:
 k=input()
 i=192
 count=0
 while True:
  c=str(pow(i,3))
  #print c
  x=int(c[-3:])
  if x == 888 :
   count=count+1
  if count==k:
   print i
   break
  i=i+1
 n=n-1 
   
