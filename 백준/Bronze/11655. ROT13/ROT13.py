import string
s = input()
UPPER = string.ascii_uppercase
lower = string.ascii_lowercase
sz = len(lower)
def ROT13(char):
    if char.isalpha():
        if char.isupper():
            return UPPER[(ord(char.upper())-ord('A')+13)%sz]
        else:
            return lower[(ord(char.lower())-ord('a')+13)%sz]
    else:
        return char

for char in s:
    print(ROT13(char), end='')
