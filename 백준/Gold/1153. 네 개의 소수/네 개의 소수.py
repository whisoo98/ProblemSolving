import sys

input = sys.stdin.readline
prime = [1 for _ in range(1_000_005)]
dp = [-1 for _ in range(1_000_005)]
def era():
    for i in range(2,1_002):
        if prime[i]:
            for j in range(i*i,1_000_003,i):
                prime[j]=0


def main():
    era()
    prime[0]=0
    prime[1]=0
    # for T in range(100000):
    n = int(input())
    # n = T
    if n < 8:
        print(-1)
    elif n==8:
        print(2,2,2,2)
    elif n==9:
        print(2,2,2,3)
    elif n==10:
        print(2,2,3,3)
    elif n==11:
        print(2,3,3,3)
    elif n==12:
        print(3,3,3,3)
    else:
        if n%2 == 0: # even
            ans = [2,2]
            n-=4 # n>=7
            for i in range(2,n+1):
                if prime[i] and prime[n-i]:
                    #print(i,n-i)
                    ans.append(i)
                    ans.append(n-i)
                    break
        else: # odd            
            ans = [2,3]
            
            n-=5 # n>=7
            for i in range(2,n+1):
                if prime[i] and prime[n-i]:
                    ans.append(i)
                    ans.append(n-i)
                    break
        ans.sort()
        
        for i in ans:
            print(i, end= ' ')
if __name__ == "__main__":
    main()
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    