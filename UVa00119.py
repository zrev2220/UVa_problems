def read():
    return input().strip()

doneOne = False
while True:
    try:
        people = {}
        sortedPeople = {}
        read()
        if doneOne:
            print()
        doneOne = True
        for name in read().split():
            people[name] = 0
            sortedPeople[len(sortedPeople)] = name

        for i in range(len(people)):
            data = read().split()
            name = data[0]
            money = int(data[1])
            giveN = int(data[2])
            if giveN != 0:
                toGive = money // giveN
                toKeep = money - (toGive * giveN)
                people[name] += toKeep - money
                # print(name, "keeps", toKeep)
                for recieve in data[3:]:
                    people[recieve] += toGive
                    # print(recieve, "gets", toGive)

        for key in sorted(sortedPeople.keys()):
            name = sortedPeople[key]
            print(name, people[name])

    except EOFError:
        break
