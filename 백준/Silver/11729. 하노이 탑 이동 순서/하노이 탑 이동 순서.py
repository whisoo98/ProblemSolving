def hanoi(n, fromm, to): # n번째 원판을 포함한 전체를 fromm에서 to로 옮긴다.
    if n>=1:
        other_to = list(set({1,2,3}) - set({fromm,to}))[0]
        hanoi (n-1, fromm, other_to) # n-1번째 원판을 포함한 전체를 fromm에서 other_to로 옮긴다.
        print(fromm, to) # n-1번째 원판을 fromm에서 to로 옮긴다.
        hanoi(n-1,other_to,to)
n = int(input())
print(2**n -1)
hanoi(n,1,3)