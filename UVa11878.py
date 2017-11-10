import math
import re

correct = 0
try:
	while True:
		isRight = False
		expr = input()
		if expr[-1] != '?':
			a,b,c = [int(n) for n in re.split("[^0-9]", expr)]
			correct += 1 if (expr[re.search("[0-9]+", expr).end()] == "+" and a+b == c) or a-b == c else 0
except EOFError:
	pass
print(correct)
