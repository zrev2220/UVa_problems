print(*[(lambda w, l : int(__import__("math").ceil((w - 2) / 3)) * int(__import__("math").ceil((l - 2) / 3)))(*[int(x) for x in input().strip().split()]) for _ in range(int(input().strip()))], sep="\n")
