import string

ALPHA = dict(zip( list(string.ascii_uppercase),list(range(10,36))))

num, bases = map(str,input().split())
bases = int(bases)
num = list(num)
num.reverse()
ans = 0
temp = 1
for n in num:
    if n.isalpha():
        ans += ALPHA[n]*temp
    else:
        ans += int(n)*temp
    temp *= bases
print(ans)
                  
