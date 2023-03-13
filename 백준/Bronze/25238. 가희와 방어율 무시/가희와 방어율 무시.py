a,b = map(int,input().split())
a = a * ((100-b)/100)
if a>=100.0:
    print(0)
else:
    print(1)