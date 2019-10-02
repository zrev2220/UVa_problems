import re, math, decimal, bisect
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]
def round(n): return int(n + 0.5)

DEBUG = 1
DEBUG = 0
def debug(*args, **kwargs):
    if DEBUG: print(*args, **kwargs)

from collections import Counter
nums = dict(zip('23456789TJQKA', range(13)))
ranks = dict(zip(['high', 'pair', '2pair', '3kind', 'straight', 'flush', 'fullhouse', '4kind', 'straightflush'], range(9)))

def getrank(hand):
    freq = Counter([card[1] for card in hand])
    freq = list(zip(freq.values(), freq.keys()))
    suits = Counter([card[0] for card in hand])
    suits = list(zip(suits.values(), suits.keys()))

    getside = lambda tups, x: [t[x] for t in tups]
    freqkeys = getside(freq, 0)
    freqvals = getside(freq, 1)
    suitskeys = getside(suits, 0)
    suitsvals = getside(suits, 1)

    rank = 'high'
    tiebreak = [sorted(freqvals, reverse=True)]

    straight = True
    for i in range(1, len(hand)):
        if hand[i][1] != hand[i - 1][1] + 1:
            straight = False
            break

    debug(freq, suits, straight, sep='\n', end='\n----------\n')

    if 2 in freqkeys:
        if freqkeys.count(2) == 2:
            rank = '2pair'
        else:
            rank = 'pair'
        tiebreak = []
        for v in sorted(freq, reverse=True):
            tiebreak.append(v[1])
    if 3 in freqkeys:
        if 2 in freqkeys:
            rank = 'fullhouse'
        else:
            rank = '3kind'
        tiebreak = [freqvals[freqkeys.index(3)]]
    if 4 in freqkeys:
        rank = '4kind'
        tiebreak = [freqvals[freqkeys.index(4)]]
    if straight:
        rank = 'straight'
        tiebreak = [max(freqvals)]
    if 5 in suitskeys:
        if straight:
            rank = 'straightflush'
            tiebreak = [max(freqvals)]
        else:
            rank = 'flush'
            tiebreak = [sorted(freqvals, reverse=True)]

    debug(ranks[rank], tiebreak)
    return (ranks[rank], tiebreak)

def compare(a, b):
    pass

# code goes here
while True:
    try:
        hands = read().split()
        bhand = sorted([(c[1], nums[c[0]]) for c in hands[:5]], key=lambda card: card[1])
        whand = sorted([(c[1], nums[c[0]]) for c in hands[5:]], key=lambda card: card[1])
        brank = getrank(bhand)
        wrank = getrank(whand)
        if brank[0] == wrank[0]:
            if brank[1] == wrank[1]:
                print("Tie.")
            elif brank[1] > wrank[1]:
                print("Black wins.")
            else:
                print("White wins.")
        elif brank[0] > wrank[0]:
            print("Black wins.")
        else:
            print("White wins.")
    except EOFError:
        break
