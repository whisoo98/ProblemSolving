l = []
for _ in range(5):
    a = int(input())
    l.append(a)
l.sort()
print(int(sum(l)/len(l)))
print(l[2])