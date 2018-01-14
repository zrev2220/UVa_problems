import re
import math
import decimal
import bisect

caseno = 1
n = int(input())
while n >= 3:
	n -= 2
	print(int(math.floor(n / 2) * (math.floor(n / 2) + 1) * (8 * math.ceil(n / 2) - 2 * n - 1) / 6))

	n = int(input())
