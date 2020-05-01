
p=[]
p.append(1)
a=2
i=1
while i<=501:
  p.append(a)
  a=a<<1
  i=i+1

t=input()
while t:
  n=input()
  print (p[n+1]-1)%1298074214633706835075030044377087
  t=t-1
