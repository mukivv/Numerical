import sympy as sp

X = sp.Symbol('x')
F = sp.exp(X/3) + X**2

def f(x):
    return float(F.subs(X,x))

def forward(x,f,h):
    return ( -f(x+3*h)+4*f(x+2*h) - 5*f(x+h) + 2*f(x) ) / h**2

def backward(x,f,h):
    return ( 2*f(x) - 5*f(x-h) + 4*f(x-2*h) - f(x-3*h)) / h**2

def central(x,f,h):
    return ( -f(x+2*h) + 16*f(x+h) - 30*f(x) + 16*f(x-h) - f(x-2*h) ) / (12*h**2)

h = 0.1
x = -2.5
d = sp.diff(F,X,2)
real = float(d.subs(X,x))
print(real)

q1 = forward(x,f,h)
error = abs((real - q1) / real)
print(q1,error)

q2 = backward(x,f,h)
error = abs((real - q2) / real)
print(q2,error)

q3 = central(x,f,h)
error = abs((real - q3) / real)
print(q3,error)
