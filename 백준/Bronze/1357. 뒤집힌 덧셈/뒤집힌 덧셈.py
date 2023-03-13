n,m=map(str,input().split())
n=list(n)
m=list(m)
temp = 1
tn=0
tm=0
for i in n:
    tn +=int(i)*temp
    temp*=10
temp=1
for i in m:
    tm +=int(i)*temp
    temp*=10    
tn+=tm
tn=str(tn)
tn = tn[::-1]
tn = int(tn)
tn = str(tn)
for char in tn:
    print(char,end='')
