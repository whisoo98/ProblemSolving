n = int(input())
pos = []
neg = []
zero=[]
one=[]
sum = 0
for i in range(n):
    a= int(input())
    if a<0:
        neg.append(a)
    elif a>0:
        if a==1:
            #one.append(a)
            sum+=a
        else:
            pos.append(a)
    else:
        zero.append(a)

neg.sort()
pos.sort(reverse=True)



negLen = len(neg)
posLen = len(pos)
zeroLen = len(zero)
oneLen = len(one)

for i in range(negLen//2):
    sum+=(neg[2*i]*neg[2*i+1])

if negLen%2==1:
    if zeroLen==0:
        sum+=neg[-1]
    

for i in range(posLen//2):
    sum+=(pos[2*i]*pos[2*i+1])
    

if posLen%2==1:
    sum+=pos[-1]
    

print(sum)
