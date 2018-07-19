def isPal(n):
    if type(n) == type(int()):
        n = str(n)
    # print(n[:len(n) // 2], n[:len(n) // 2 - (len(n) % 2 ^ 1):-1])
    return n[:len(n) // 2] == n[:len(n) // 2 - (len(n) % 2 ^ 1):-1]

for _ in range(int(input())):
    n = input()
    i = 0
    while not isPal(n):
        n = str(int(n) + int(str(n)[::-1]))
        i += 1
        # print(n)
    print(i, n)
