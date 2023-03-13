total = int(input())
n = int(input())
cal=0

for _ in range(0,n):
    price, num = map(int, input().split())
    cal += price * num
    
if cal == total:
    print("Yes")
else:
    print("No")
