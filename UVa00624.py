import re, math, decimal, bisect
import sys
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]
def round(n): return int(n + 0.5)

DEBUG = 1
DEBUG = 0
def debug(*args, **kwargs):
    if DEBUG: print(*args, **kwargs)

tracks = []
best = (0, 0)
cap = 0

def fun(idx, space, used):
    global best
    if space < 0:
        return
    if space == 0:
        best = (cap - space, used)
        return
    if idx >= len(tracks):
        if cap - space > best[0]:
            best = (cap - space, used)
        return

    debug(" "*idx, "try {}, space = {}".format(tracks[idx], space - tracks[idx]))
    fun(idx + 1, space - tracks[idx], used | (1 << idx))
    debug(" "*idx, "skip {}, space = {}".format(tracks[idx], space))
    fun(idx + 1, space, used)

# code goes here
while True:
    try:
        data = viread()
        cap = data[0]
        n = data[1]
        tracks = data[2:]
        best = (0, 0)

        fun(0, cap, 0)

        ans = []
        for i in range(n):
            if best[1] & (1 << i):
                ans.append(tracks[i])
        print(*ans, "sum:{}".format(best[0]))
    except EOFError:
        break
