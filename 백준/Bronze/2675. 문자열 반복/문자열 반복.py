T = int(input())

for t in range(T):
    num, S = map(str,input().split())
    num = int(num)
    new_str =''
    for s in S:
        new_str += s*num
    print(new_str)
