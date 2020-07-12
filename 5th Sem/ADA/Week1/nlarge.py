print("enter array ")
arr = input()
a = list(map(int,arr.split(' ')))
k = int(input("enter the k large number you want "))
n =len(a)
if k>n:
	print("array index out of range : enter within 7")
else:
	for i in range(0,k):
		max_index = i
		for j in range(i+1,n):
			if a[j]>a[max_index]:
				max_index =j
		temp = a[max_index]
		a[max_index]=a[i]
		a[i] = temp
		print(a[i])
			


"""
enter array 
3 1 5 4 27
enter the k large number you want 3
27
5
4
"""
