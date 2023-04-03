def main():
    n = int(input())
    pattern = input()

    for _ in range(n):
        file = input()
        print(doTranslation(pattern, file))
    
    
    
def doTranslation(pattern, file):
    idx = pattern.find('*')
    
    pattern_front = pattern[:idx]
    
    pattern_back = pattern[idx+1:]
    pattern_back = pattern_back[::-1]
    
    file_reverse = file[::-1]
    ans = ''
    if len(file)+1<len(pattern):
        ans = 'NE'
    elif file[:idx]==pattern_front and \
        file_reverse[:len(pattern_back)] == pattern_back:
        ans = 'DA'
    else:
        ans = 'NE'
    return ans

if __name__ == "__main__":
    main()