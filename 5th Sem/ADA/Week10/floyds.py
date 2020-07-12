a = [[0,1,999,999,999,2],[1,0,2,5,999,999],[999,2,0,6,4,999],[999,5,6,0,3,999],[999,999,4,3,0,6],[2,999,999,999,6,0]]

for k in range(0,len(a)):
	for i in range(0,len(a)):
		for j in range(0,len(a)):
			a[i][j] = min((a[i][k]+a[k][j]),a[i][j])

for i in range(0,len(a)):
	for j in range(0,len(a)):
		print(a[i][j],end=" ")
	print()
	
		
	
