n,k = map(int,input().split())
s = ''
tot_len =0
nstring = str(n)
lenarr=[]

for l in range(1,9):
    mul=9*(10**(l-1))
    lenarr.append(l*mul)
lenarr.append(9)

if len(nstring)>1:
    for l in range(0,len(nstring)-1):
        tot_len += lenarr[l]
    least = n-(10**(len(nstring)-1))+1
    if len(nstring)==9:
        least = 1
    tot_len += least*len(nstring)
    #print(least)
    #print(tot_len)
else:
    tot_len += n*len(nstring)
    lenarr.append(9)

if k>tot_len:
    print(-1)
elif n<10:
    for i in range(1,n+1):
        s+=str(i)
    print(s[k-1])
else:
    temp = k
    for idx, i in enumerate(lenarr):
        temp -= i
        if temp<0:
            temp+=i
            length = idx+1
            break
    cnt = n - int((10**(idx)))+1
    #print(cnt, temp, idx)
    ST = int(10**(idx))
    #print(temp)
    for st,i in enumerate(range(cnt)):
        temp-=(idx+1)
        if temp<0:
            temp+=(idx+1)
            break;
    if st==0:
        st =1
    st = st+ST-1
    #print(temp)
    if temp==0:
        print(str(st)[-1])
    else:
        for j in str(st):
            if temp==1:
                print(j)
                break
            temp-=1
