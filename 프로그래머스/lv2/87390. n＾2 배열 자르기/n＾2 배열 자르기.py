import numpy as np
def solution(n, left, right):
    mok_left, rest_left = divmod(left,n)
    mok_right, rest_right = divmod(right,n)
    # if(rest_left ==0):
    #     mok_left-=1
    # if rest_right == 0:
    #     mok_right -=1
    answer =[]
    left_l=[]
    right_l = []
    if(mok_left == mok_right):
        for i in range(rest_left,rest_right+1):
            if i<= mok_left:
                left_l.append(mok_left+1)
            else:
                left_l.append(i+1)
        return left_l
    
    
    for i in range(rest_left,n):
        if i<= mok_left:
            left_l.append(mok_left+1)
        else:
            left_l.append(i+1)
   
    
    middle_l = []
    for i in range(mok_left+1,mok_right):
        for j in range(n):
            if j<=i:
                middle_l.append(i+1)
            else:
                middle_l.append(j+1)
                
                
    for i in range(rest_right+1):
        if i<= mok_right:
            right_l.append(mok_right+1)
        else:
            right_l.append(i+1)
            
    answer  =[]
    answer = left_l + middle_l + right_l
        
    return answer