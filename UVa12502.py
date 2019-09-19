import re, math, decimal, bisect
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]
def round(n): return int(n + 0.5)

DEBUG = 1
# DEBUG = 0
def debug(*args, **kwargs):
    if DEBUG: print(*args, **kwargs)
    
# code goes here
t = iread()
for i in range(t):
    x, y, z = viread()
    print((z * (3*x - (x+y))) // (x+y))
