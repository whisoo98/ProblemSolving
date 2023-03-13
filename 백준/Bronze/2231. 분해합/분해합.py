def const(l, Const):
    for i in range(1,1_000_001):
        j = i
        sum = i
        while i:
            sum += i%10
            i //= 10
        l[j]=sum
        Const[sum] =min(Const[sum], j)


l = [0 for _ in range(1_000_003)]
Const = [987654321 for _ in range(2_000_003)]
const(l, Const)
n = int(input())
print(Const[n] if Const[n] != 987654321 else 0)