import random
def fusion(t1,t2):
	t3=[]
	i=0
	j=0
	while len(t3) != len(t1)+len(t2):
		if i != len(t1) and j != len(t2):
			if t1[i] < t2[j]:
				t3+=[t1[i]]
				i+=1
			else:
				t3+=[t2[j]]
				j+=1
		elif i == len(t1):
			t3+=[t2[j]]
			j+=1
		else:
			t3+=[t1[i]]
			i+=1
	return(t3)
def trie(t1):
	if len(t1)==1:
		return(t1)
	else:
		return(fusion(trie(t1[0::2]),trie(t1[1::2])))
a=[]
for i in range(20):
	a+=[random.randint(1,50)]
print(trie(a))