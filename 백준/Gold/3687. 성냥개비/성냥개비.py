def Big(n):
    ans= ''
    temp = n
    while temp>3:
        temp -= 2
        ans += '1'
    if temp==2:
        ans += '1'
    else:
        ans = '7' + ans
    return ans

def Small(n):
    ans = ''
    temp = n
    mok, rest = divmod(temp,7)
    if rest:
        mok+=1
    mok-=3
    mok = 0 if mok<0 else mok
    ans += '8'*mok
    
    temp -= mok*7
    if temp == 2:
        ans='1'+ans
    elif temp == 3:
        ans = '7'+ans
    elif temp == 4:
        ans = '4'+ans
    elif temp == 5:
        ans = '2' + ans
    elif temp == 6:
        ans = '6' + ans
    elif temp == 7:
        ans = '8' + ans
    elif temp == 8:
        ans = '10' + ans
    elif temp == 9:
        ans = '18' + ans
    elif temp == 10:
        ans = '22' + ans
    elif temp == 11:
        ans = '20' + ans
    elif temp == 12:
        ans = '28' + ans
    elif temp == 13:
        ans = '68' + ans
    elif temp == 14:
        ans = '88' + ans
    elif temp == 15:
        ans = '108' + ans
    elif temp == 16:
        ans = '188' + ans
    elif temp == 17:
        ans = '200' + ans
    elif temp == 18:
        ans = '208' + ans
    elif temp == 19:
        ans = '288' + ans
    elif temp == 20:
        ans = '688' + ans
    elif temp == 21:
        ans = '888' + ans
    return ans

def Solution(n):
    big = Big(n)
    small = Small(n)
    print(small, big)


T = int(input())

while T:
    T-=1
    n = int(input())
    Solution(n)
