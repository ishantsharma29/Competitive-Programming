def fac(n):
 if n==1 or n==2:
  return n
 else:
  return n*fac(n-1)

t=input()
while t:
 n=input()
 p=fac(n)
 print p
 t=t-1
