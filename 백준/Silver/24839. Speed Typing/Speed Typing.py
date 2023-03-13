T = int(input())
for t in range(T):
    strings = input()
    produceds = input()
    idx=0
    chk=0
    summation=0
    if len(strings)>len(produceds):
        print("Case #{0}: IMPOSSIBLE".format(t+1))
        continue
    for s in strings:
        temp = produceds.find(s)
        if temp == -1:
            chk=1
            break
        summation+=(temp-idx)
        #print(temp)
        idx = 0
        produceds = produceds[temp+1:]
    if chk:
        print("Case #{0}: IMPOSSIBLE".format(t+1))
    else:
        summation+=len(produceds)
        print("Case #{0}: {1}".format(t+1,summation))
        
        
