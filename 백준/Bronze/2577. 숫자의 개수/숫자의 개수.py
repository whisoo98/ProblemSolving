a  = input()
b  = input()
c  = input()

d = str(int(a)*int(b)*int(c))
for i in range(0,10):
    print(d.count(str(i)))