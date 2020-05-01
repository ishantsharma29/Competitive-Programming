import sys
 
def bishops(N):
  if N==1:
    return 1
  else:
    return 2*N-2

 
while True:
    try:
        v = input()
    except EOFError:
        break
    
    v=int(v)
    ans=bishops(v)
    print(ans)


