import sys
input = sys.stdin.readline

def main():
    n,k = map(int,input().split())
    efficiency = [0 for _ in range(n+5)]
    psum = [0 for _ in range(n+5)]
    dp = [0 for _ in range(n+5)]
    
    deque =[]
    for i in range(1,n+1):
        efficiency[i] = int(input())
        psum[i] = psum[i-1] + efficiency[i]
    
    for i in range(1,n+1):
        while len(deque) and deque[0] < i - k:
            deque.pop(0)
            
        while len(deque) and \
            (dp[deque[-1]-1] - psum[deque[-1]]) < dp[i-1] - psum[i]:
            deque.pop()
        deque.append(i)
        dp[i] = psum[i] + dp[deque[0]-1] - psum[deque[0]]
        if i<=k:
            dp[i] = max(dp[i],psum[i])
    
    print(dp[n])
    
    
    
    # for i in range(1,n+1):
    #     for j in range(i-k,i+1):
    #         if j<0:
    #             continue
    #         dp[i] = max(dp[i], psum[i] + (dp[j-1] - psum[j]))
    
    # print(dp[n])
    
        
        
if __name__ == "__main__":
    main()