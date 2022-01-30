import math

p = math.log2(3)
print("p es ", p)
n = int(input())
x = pow(n, p)
y = x - (0.81255*x)
t2 = x - y
ans = math.ceil(t2 + 1)
print(ans)