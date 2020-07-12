import random
import string

def password(n):
	chars = string.ascii_letters + string.digits + string.punctuation
	return "".join(random.choice(chars) for x in range(n))


n = int(input("enter the length of password you want"))
p = password(n)
print(p)
