import sys

input =sys.stdin.readline



def parseExp(exp):
    for idx,is_op in enumerate(exp):
        if not is_op.isdecimal() and idx!=0:
            op = is_op
            num1 = exp[:idx]
            num2 = exp[idx+1:]
            break
    num1= str(int(num1,8))
    num2= str(int(num2,8))
    if op=='/' and num2=='0':
        ans = 'invalid'
    else:
        if op=='/':
            op='//'
        ans = int(eval('{0}{1}{2}'.format(num1,op,num2)))
        if ans < 0:
            ans = '-' + oct(ans)[3:]
        else:
            ans = oct(ans)[2:]
    return ans      
    
    


def main():
    exp = input()
    print(parseExp(exp))




if __name__ == '__main__':
    main()