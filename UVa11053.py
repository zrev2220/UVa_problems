import math

a = 0
b = 0
N = 0

def f(x):
	return ((a * x * x) + b) % N
	
def cycleFinding(x0):
	tortoise = f(x0)
	hare = f(f(x0))
	while tortoise != hare:
		tortoise = f(tortoise)
		hare = f(f(hare))
		
	mu = 0
	hare = x0
	while tortoise != hare:
		tortoise = f(tortoise)
		hare = f(hare)
		mu += 1
		
	lamb = 0
	hare = f(tortoise)
	while tortoise != hare:
		hare = f(hare)
		lamb += 1
		
	return [mu, lamb]
	
N, a, b = [int(x) for x in input().split(" ")]
while True:
	result = cycleFinding(0)
	# print("mu:{} lambda{}: ans:{}".format(result[0], result[1], N - result[1] - 1))
	print("{}".format(N - result[1] - 1))
	try:
		N, a, b = [int(x) for x in input().split(" ")]
	except ValueError:
		break
