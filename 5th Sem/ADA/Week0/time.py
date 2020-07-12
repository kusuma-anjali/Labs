import random
import time
arr =[]
def selection(a,n):
	for i in range(0,n-1):
		max_index = i
		for j in range(i+1,n):
			if a[j]>a[max_index]:
				max_index =j
		temp = a[max_index]
		a[max_index]=a[i]
		a[i] = temp

def bubble(a,n):
	for i in range(0,n-1):
		for j in range(0,n-1-i):
			if a[j]>a[j+1]:
				temp = a[j]
				a[j]=a[j+1]
				a[j+1] = temp


n=500

for i in range(0,n):
	arr.append(random.randint(0,100))

arr1=arr
		
start = time.time()
selection(arr1,n)
end = time.time()

start1 = time.time()
bubble(arr,n)
end1 = time.time()

print("selction:" ,(end-start))
print("bubble:" ,(end1-start1))

