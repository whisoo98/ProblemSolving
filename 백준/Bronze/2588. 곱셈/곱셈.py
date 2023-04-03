a = int(input())
b = int(input())

strb = str(b)
ans = list()
for i in range(2,-1,-1):
    print(a*int(strb[i]))
    
print(a*b)


