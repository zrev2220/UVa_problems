import re

N = int(input())
for i in range(N):
	C = int(input().strip())
	keywords = {}
	reqs = {}
	for j in range(C):
		catLine = [p for p in re.sub("[^A-Za-z0-9]", " ", input().strip()).split(" ") if p != ""]
		category = catLine[0]
		words = int(catLine[1])
		req = int(catLine[2])
		reqs[chr(j) + category] = req
		for k in range(words):
			word = input().strip()
			if word not in keywords:
				keywords[word] = set()
			keywords[word].add(chr(j) + category)
	reqs["42"] = 42
	line = input()
	while line.strip():
		words = re.sub("[^A-Za-z]", " ", line).split(" ")
		for word in words:
			if word in keywords.keys():
				category = keywords[word]
				keywords[word] = {"42"}
				for cat in category:
					reqs[cat] = max(0, reqs[cat] - 1)
		try:
			line = input()
		except EOFError:
			break
	probTypes = []
	for key in sorted(reqs.keys()):
		if key == "42":
			continue
		if reqs[key] <= 0:
			probTypes.append(key[1:])
	if len(probTypes) == 0:
		print("SQF Problem.")
	else:
		print(*probTypes, sep=",")
