with open('f1.txt','w') as f:
    f.write("Welcome to BMSCE")
output = ""
i=1
with open('f1.txt','r') as f:    
    li=len(f.read())
    print(li)
    while i<(li+1) : 
        f.seek(li-i)
        output+=f.read(1)
        i=i+1
print(output)       



