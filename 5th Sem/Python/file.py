import math


with open ('f1.txt','w') as wf:
    wf.write("Welcome to BMSCE")

with open ('f2.txt','w') as wf1:
    wf1.write("what is your name")

with open ('f1.txt','r') as rf:
    str1=rf.readline()

with open ('f2.txt','r') as rf1:
    str2=rf1.readline()
temp=" "
str1= str1.split()
str2= str2.split()
for x in range(min(len(str1),len(str2))):
    temp=temp+ str1[x][:math.ceil(len(str1[x])/2)]+str2[x][:math.ceil(len(str2[x])/2)]+" "
                                                             
x=x+1          
if x>len(str1):
    for x in range(x,max(len(str1),len(str2))):
      temp=temp+ str1[x][:math.ceil(len(str1[x])/2)]+" "
else:
    for x in range(x,max(len(str1),len(str2))):               
      temp=temp+ str2[x][:math.ceil(len(str2[x])/2)]+" "
print(temp)                                                              
           

with open ('f3.txt','w') as wf2:
    wf2.write(temp)
