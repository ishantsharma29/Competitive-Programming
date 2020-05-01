import random

t=input()
#print t


while t>0:
	#print t
	num= list( raw_input() )
	#print num
	#for i in xrange(0):
	#	random.shuffle(num)
	size = input()
	a=raw_input().split(" ")
	#print a
	b="".join(num)
	c=int(b)
	#print c
	sum=0
	minimum=0
	for e in a:
		e=int(e)
		sum=sum+c%e
	#print sum
	minimum=sum
	res=num
	for i in xrange(260):
		random.shuffle(num)
		#random.shuffle(num)
		#print num
		b="".join(num)
		c=int(b)
		#print c
		sum=0
		for e in a:
			e=int(e)
			sum=sum+c%e
		#print sum
		if sum < minimum :
			minimum=sum
			res=num
			#print "res " , res
	print "".join(res)		
	t=t-1
