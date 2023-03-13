n = int(input())
s = ''
for i in range(n*2-1):
    if i%2 == 0:
        s+='*'
    else:
        s+=' '

for i in range(n):
    if i % 2 ==0:
        print(s)
    else:
        print(' '+s)
    