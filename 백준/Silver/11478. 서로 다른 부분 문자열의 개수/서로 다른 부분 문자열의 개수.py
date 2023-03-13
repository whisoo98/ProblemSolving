
import sys
sys.setrecursionlimit(10**6)

S = input().strip()
s = set()
length = len(S)

# for i in range(length):
for j in range(length):
    for k in range(length-j): # 최소 0 생성
        tmp = S[j:j+k+1]
        # print(f'tmp = {tmp}, i = {i}, j = {j}, k = {k}')
        if tmp not in s:
            s.add(tmp)
            
        

print(len(s))