import math
import re

for i in range(int(input())):
	m = int(input())
	wonderful = True
	div = [int(x) for x in input().split(" ")]
	for j in range(1, len(div)):
		if m % div[j] != 0:
			wonderful = False
			break
	print("{} - {}.".format(m, "Wonderful" if wonderful else "Simple"))
