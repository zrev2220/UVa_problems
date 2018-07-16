print(*[''.join([chr(ord(c) - 7) for c in code[:-1]]) for code in [line.strip() for line in __import__("sys").stdin]], sep="\n")
