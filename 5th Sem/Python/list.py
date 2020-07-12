c = input("enter a string")
c= c.split()
d=c[: :-1]
s=" "
s = s.join(d)
print(s)

for char in c:
    char = char[ : :-1]
    print(char,end=" ")
