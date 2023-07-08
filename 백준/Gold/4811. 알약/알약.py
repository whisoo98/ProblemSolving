import sys
sys.setrecursionlimit(100_000)
input = sys.stdin.readline

dp = [0 for _ in range(35)]
pill = [[0 for _ in range(75)] for _ in range(75)]

# def findPillString(w, h):
#     if pill[w][h] != 0:
#         return pill[w][h]
#     if w==0:
#         pill[w][h] = 1
#         return pill[w][h]
    
#     if h==0:
#         pill[w][h] = findPillString(w-1,h+1)
#     else:
#         pill[w][h] = findPillString(w-1,h+1) + findPillString(w,h-1)
#     return pill[w][h]

    
def findPillString():
    global pill
    for h in range(70):
        pill[0][h] = 1
    # pill[0][0] = 0
    for w in range(1,70):
        for h in range(0,70):
            if h == 0:
                pill[w][h] = pill[w-1][h+1]
            else:
                pill[w][h] = pill[w-1][h+1] + pill[w][h-1]

            
    
    

def getPillString(i):
    return pill[i][0]
    
def preprocess():
    global dp
    findPillString()
    for i in range(1, 31):
        # dp[i] = findPillString(i,0)
        dp[i] = getPillString(i)

def main():
    global dp
    preprocess()
    while True:
        n = int(input())
        if n == 0:
            break
        print(dp[n])



if __name__ == "__main__":
    main()