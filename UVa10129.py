import re, math, decimal, bisect
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]

# code goes here
for _ in range(iread()):
	start = [0 for i in range(26)]
	end = [0 for i in range(26)]
	for i in range(iread()):
		word = read()
		start[ord(word[0]) - ord('a')] += 1
		end[ord(word[-1]) - ord('a')] += 1
	exceptions = 2
	amatch = False
	for i in range(26):
		if start[i] == 0 and end[i] == 0:
			continue
		if start[i] != end[i]:
			exceptions -= 1
		if start[i] > 0 and end[i] > 0:
			amatch = True
	if exceptions < 0 or not amatch:
		print("The door cannot be opened.")
	else:
		print("Ordering is possible.")
