a,b = map(int,input().split())
l = [i for i in range(100) for _ in range(i)]
print(sum(l[a-1:])-sum(l[b:]))