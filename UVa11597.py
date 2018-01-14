import re
import math
import decimal
import bisect

caseno = 1
n = int(input())
while n != 0:
	e = (n * (n - 1)) / 2
	t = n - 1
	ans = 0
	while e >= t:
		e -= t
		ans += 1

	print("Case {}: {}".format(caseno, ans))
	caseno += 1

	n = int(input())
  
