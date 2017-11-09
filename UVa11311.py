import math

for i in range(int(input())):
	m,n,r,c = [int(x) for x in input().split(" ")]
	print("{} ^ {} ^ {} ^ {} = {}".format(r * m, c * n, (r - n - 1) * m, (c - m - 1) * n, (r * m) ^ (c * n) ^ ((r - n - 1) * m) ^ ((c - m - 1) * n)))
	print("Gretel" if ((r * m) ^ (c * n) ^ ((r - n - 1) * m) ^ ((c - m - 1) * n)) != 0 else "Hansel")
