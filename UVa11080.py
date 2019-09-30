import re, math, decimal, bisect
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]
def round(n): return int(n + 0.5)

DEBUG = 1
DEBUG = 0
def debug(*args, **kwargs):
    if DEBUG: print(*args, **kwargs)
    
# code goes here
t = iread()
for _t in range(t):
    V, E = viread()
    adjlist = [[] for _ in range(V)]
    for i in range(E):
        a, b = viread()
        adjlist[a].append(b)
        adjlist[b].append(a)

    debug(adjlist)
    # do bfs for each CC
    possible = True
    guards = 0
    visited = 0
    dist = [-1] * V
    s = 0
    while visited < V and possible:
        debug(s, visited)
        even, odd = 1, 0
        dist[s] = 0
        q = [s]
        while q and possible:
            debug(q, dist)
            u = q.pop(0)
            visited += 1
            for v in adjlist[u]:
                if dist[v] == -1:
                    dist[v] = dist[u] + 1
                    if dist[v] % 2:
                        odd += 1
                    else:
                        even += 1
                    q.append(v)
                elif dist[v] % 2 == dist[u] % 2:
                    possible = False
                    break
        debug("evenodd:", even, odd)
        guards += min(even, max(1, odd))
        debug(guards, "guards")

        # find next source
        while s < V and dist[s] != -1:
            s += 1
        debug(f"End of loop; s: {s} visited: {visited} dist:\n{dist}")
    debug(*enumerate(dist))
    if possible:
        print(guards)
    else:
        print(-1)
