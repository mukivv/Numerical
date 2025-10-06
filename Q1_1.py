import numpy as np
from scipy.integrate import quad

def f(x):
    ans = x**7 + 2*(x**3) -1
    print(ans)
    return ans

a,b = -1,2

def simp(f,a,b):
    h = (b-a)/2
    return h/3 * (f(a) + f(b) + 4*f(a+h))

def com(f,a,b,n):
    h = (b-a) / (2*n)
    s = f(a) + f(b)
    for i in range (1,2*n):
        if (i%2 == 0):
            s += 2* f(a+i*h)
        else:
            s += 4* f(a+i*h)
    return h/3 * s

real,_ = quad(f,a,b)

si = simp(f,a,b)
err1 = abs((real-si)/real)

print (si,err1)

for i in range(2, 7, 2):
    ci = com(f, a, b, i)
    err = abs((real - ci) / real)
    print(i,ci,err)
