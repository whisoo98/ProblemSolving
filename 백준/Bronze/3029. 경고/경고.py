import sys

input = sys.stdin.readline

h1, m1, s1 = map(int, input().split(":"))
h2, m2, s2 = map(int, input().split(":"))

tot1 = h1 * 3600 + m1 * 60 + s1

tot2 = h2 * 3600 + m2 * 60 + s2


if tot2 < tot1:
    tot2 += 24 * 3600

tot2 -= tot1
if(tot2 == 0):
    tot2 = 24*3600  
h3 = tot2 // 3600
tot2 %= 3600
m3 = tot2 // 60
tot2 %= 60
s3 = tot2

print("{0:0>2}:{1:0>2}:{2:0>2}".format(h3, m3, s3))
