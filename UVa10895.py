while True:
	try:
		line = input().strip().split(" ")
		m = int(line[0])
		n = int(line[1])
		matrix = [[0 for n in range(n)] for r in range(m)]
		for i in range(m):
			line = input().strip().split(" ")
			r = int(line[0])
			if int(line[0]) == 0:
				input()
				continue
			elems = input().strip().split(" ")
			for j in range(r):
				matrix[i][int(line[j + 1]) - 1] = int(elems[j])
		# print(matrix)
		matrix = [[row[i] for row in matrix] for i in range(n)]
		# print(matrix)
		print("{} {}".format(n, m))
		for i in range(n):
			print(sum(1 if x != 0 else 0 for x in matrix[i]), end="")
			for j in range(m):
				if matrix[i][j] != 0:
					print(" {}".format(j + 1), end="")
			print()
			printedYet = False
			for j in range(m):
				if matrix[i][j] != 0:
					if not printedYet:
						printedYet = True
					else:
						print(" ", end="")
					print("{}".format(matrix[i][j]), end="")
			print()
	except EOFError:
		break
