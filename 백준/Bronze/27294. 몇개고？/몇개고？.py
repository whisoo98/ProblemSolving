T,S = map(int,input().split())
chk = 0
if S ==0 and (T>=12 and T<=16):
    chk=1
if chk==1:
    print(320)
else:
    print(280)