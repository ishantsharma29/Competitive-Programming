def fac(x):
 b=1
 for i in range(1,x+1,1):
  b=(b*i)
 return b 

n=raw_input()
m=1000000007
a=n.split(' ')
x=int(a[0])
y=int(a[1])
z=int(a[2])
p=int(a[3])
#print x,y,z,p

x=fac(x)
print x
y=fac(y)
print y
z=fac(z)
print z
p=fac(p)
print p
c=(y*z*p)
print c
d=(x/c)%m
print d 
