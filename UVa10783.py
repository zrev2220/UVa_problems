T = int(input())
case = 0
while (T > 0):
	case += 1
	a = int(input())
	b = int(input())
	l = min(a, b)
	h = max(a, b)
	if (l % 2 == 0):
		l += 1
	if (h % 2 == 0):
		h -= 1
	
	print("Case {}: {}".format(case, sum(range(l, h + 1, 2))))
	
	T -= 1
