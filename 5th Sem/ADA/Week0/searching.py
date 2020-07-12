a=[]
b=[]
f=open("test.txt","r")
if f.mode =="r":
    c = f.readline()
    x=int(c)
    while x>1:
        d = f.readline()
        a = list(map(int,d.split()))
        k=a[1]
        n=a[0]
        e=f.readline()
        b = list(map(int,e.split()))
        beg =0
        end = n-1
        while beg<=end:
            mid = int((beg+end)/2)
            if k ==b[mid]:
                print(1)
                break
            elif k<b[mid]:
                end = mid-1
            else:
                beg = mid+1
        print(-1)
        x=x-1
    
    

