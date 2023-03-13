lowercase =0
UPPERCASE =0
number =0
spaces = 0

def counting(char):
    if char.isnumeric():
        global number
        number+=1
    elif char.islower():
        global lowercase
        lowercase+=1
    elif char.isupper():
        global UPPERCASE
        UPPERCASE +=1
    elif char.isspace():
        global spaces
        spaces += 1
        
while True:
    try:
        lowercase =0
        UPPERCASE =0
        number =0
        spaces = 0
        s = input()
        for char in s:
            counting(char)
        print(lowercase, UPPERCASE, number, spaces)
    except Exception as e:
        break
