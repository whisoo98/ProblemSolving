n = int(input())
l = [0 for _ in range(205)]
a = list(map(int,input().split()))
for i in a:
    l[i+100]+=1
target = int(input())
print(l[target+100])