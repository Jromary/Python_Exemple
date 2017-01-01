import random
def hop(t):
	nbc=0
	T=[]
	if len(t)==1:
		return t
	for i in t:
		T+=[[i]]
	while len(T)>1:
		n=0
		while 2*n+1 < len(T):
			if T[2*n][0] < T[2*n+1][0]:
				T[2*n],T[2*n+1] = T[2*n+1],T[2*n]
			nbc+=1
			T[2*n]+=[T[2*n+1][0]]
			n+=1
		T=T[0::2]
	nbc+=len(T[0])-2
	return(T[0][0],max(T[0][1::]),nbc)
####
a=[]
b=0
for i in range(100):
	for i in range(100):
		a+=[random.randint(-100,100)]
	x=hop(a)
	b=max(x[2],b)
	print(x[2])
	a=[]
print("\n"+str(b))
####