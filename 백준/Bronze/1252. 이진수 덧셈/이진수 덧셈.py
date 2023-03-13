a,b = map(str,input().split())
a=a[-1::-1]
b=b[-1::-1]
L = max(len(a),len(b))
l = min(len(a),len(b))
(a,b) = (b,a) if len(a)<len(b) else (a,b)
carry = 0
ans = ''
for i in range(L):
    if i >= l:
        digit = int(a[i]) +carry
    else:
        digit=int(a[i])+int(b[i])+carry
    ans+=str(digit%2)
    carry = digit//2
ans+=str(carry)
ans=ans[-1::-1]
ans=int(ans)
print(ans)
