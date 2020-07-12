print("enter array ")
arr = input()
a = list(map(int,arr.split(' ')))
k = int(input("enter the kth smallest number you want"))
n = len(a)
if k>n:
	print("array index out of range : enter within 7")
else:
	for i in range(0,k):
		min_index = i
		for j in range(i+1,n):
			if a[j]<a[min_index]:
				min_index =j
		temp = a[min_index]
		a[min_index]=a[i]
		a[i] = temp

	print(a[k-1])
			

"""
enter array 
3 5 11 1 50
enter the kth smallest number you want4
11
"""
