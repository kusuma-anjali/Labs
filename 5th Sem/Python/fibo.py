def fibo(n):
	li=[]
	li.append(0)
	li.append(1)
	if n==1:
		print(li[0])
	elif n==2:
		print(li[0],li[1])
	elif n>2:
		for i in range(2,n):
			li.append(li[i-1]+li[i-2])
		print(li)


n = int(input("enter the number of fibo numbers to be generated"))
fibo(n)
