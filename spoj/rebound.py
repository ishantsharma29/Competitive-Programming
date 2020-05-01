import math
n=input()
var='Not this time.'

for i in range(n):
 a=raw_input()
 b=a.split(' ')
 x=int(b[0])
 y=int(b[1])
 z=int(b[2])
 d=((4*z*z*x*x)+(8*z*z*z*y+4*z*z*y*y))
 #print d
 #if d < 0:
  #print var
  #continue
 p=math.sqrt(d)
 #print p
 f=2*z*x
 #print f
 g=((4*z)+2*y)
 #print g 
 r1=(f+p)/g
 r2=math.trunc(r1)
 r3=math.modf(r1)
 #print r3
 r4=math.ceil(r1)
 if r4 > r1:
  print var
  continue
 print r2
 
  
