import random
import string

def password(n):
	chars = string.ascii_letters + string.digits + string.punctuation
	li = []
	li.append(random.choice(string.ascii_lowercase))
	li.append(random.choice(string.ascii_uppercase))
	li.append(random.choice(string.digits))
	li.append(random.choice(string.punctuation))
	
	for i in range(n-4):
		li.append(random.choice(chars))

	random.shuffle(li)
	print("".join(li))
		
n = int(input("enter a number"))
password(n)

