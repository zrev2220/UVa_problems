import math
import re

for i in range(int(input())):
	numbers = []
	for j in range(int(input())):
		numbers.append(input().strip())
	numbers = sorted(numbers)
	consistent = True
	for n in range(0, len(numbers) - 1):
		consistent = not numbers[n + 1].startswith(numbers[n])
		if not consistent:
			break
	print("YES" if consistent else "NO")
