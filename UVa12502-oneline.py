print(*[(lambda x,y,z: (z * (3*x - (x+y))) // (x+y))(*[int(_2) for _2 in input().strip().split()]) for _1 in range(int(input().strip()))], sep="\n")
