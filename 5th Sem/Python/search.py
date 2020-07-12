def fun(l,n):
    return n in l

print("enter the list")
a=input()
li = list(map(int,a.split()))
n=int(input("enter the number to be searched: "))
ans=fun(li,n)
print(ans)
