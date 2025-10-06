import numpy as np
from math import factorial
import sympy as sp

X = sp.Symbol('x')
F = sp.exp(X)

def f(x):
    return np.exp(x)

def forward(x,f,n,h):
    sum = 0
    for i in range (n+1):
        sum += ((-1)**i) * (factorial(n) / (factorial(i)*factorial(n-i))) * f(x + (n - i)*h)
    return sum / h**n

def backward(x,f,n,h):
    sum = 0
    for i in range (n+1):
        sum += ((-1)**i) * (factorial(n) / (factorial(i)*factorial(n-i))) * f(x - i*h)
    return sum / h**n

def central(x,f,n,h):
    sum = 0
    for i in range(-n, n+1):
        sum += ((-1)**i) * factorial(2*n) / (factorial(n+i) * factorial(n-i)) * f(x + i*h)
    return sum / (2**(n%2) * h**n)

h = 0.25
x = 2
d = sp.diff(F,X)
real = float(d.subs(X,x))
print(real)

q1 = forward(x,f,1,h)
error = abs((real - q1) / real)
print(q1,error)

q2 = backward(x,f,1,h)
error = abs((real - q2) / real)
print(q2,error)

q3 = central(x,f,1,h)
error = abs((real - q3) / real)
print(q3,error)
