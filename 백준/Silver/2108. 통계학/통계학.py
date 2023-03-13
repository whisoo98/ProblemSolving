import sys
input = sys.stdin.readline

n = int(input())
l = []
C = [0 for _ in range(8005)]
for _ in range(n):
    i = int(input())
    l.append(i)
    C[i+4000] += 1

arithmean = sum(l)/len(l)
mok = sum(l)//len(l)
rest = arithmean - mok
if rest>=0.5:
    mok+=1
scope1 = max(l)-min(l)
l.sort()
median = l[n//2]
if C.count(max(C)) > 1:
    idx = C.index(max(C))
    
    idx2= C[idx+1:].index(max(C)) + idx + 1
    
else:
    idx2 = C.index(max(C))
mode = idx2-4000    
print(mok)
print(median)
print(mode)
print(scope1)
