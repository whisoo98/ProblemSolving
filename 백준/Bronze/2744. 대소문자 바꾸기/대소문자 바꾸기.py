s = input()
for ch in s:
    if ch.isupper()==True: 
        print(ch.lower(),end='')
    else:
        print(ch.upper(),end='')