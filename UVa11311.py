import math

for i in range(int(input())):
	m,n,r,c = [int(x) for x in input().split(" ")]
	print("Gretel" if (r ^ c ^ (m - r - 1) ^ (n - c - 1) != 0) else "Hansel")
