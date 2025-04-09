import random

s2n = {
    'GO': 0, 'A1': 1, 'CC1': 2, 'A2': 3, 'T1': 4, "R1": 5, "B1": 6, 'CH1': 7, 'B2': 8, 'B3': 9,
    "JAIL": 10, 'C1': 11, "U1": 12, 'C2': 13, 'C3': 14, 'R2': 15, 'D1': 16, 'CC2': 17, 'D2': 18, "D3": 19,
    'FP': 20, 'E1': 21, 'CH2': 22, 'E2': 23, 'E3': 24, 'R3': 25, 'F1': 26, 'F2': 27, 'U2': 28, 'F3': 29,
    'G2J': 30, 'G1': 31, "G2": 32, 'CC3': 33, "G3": 34, "R4": 35, 'CH3': 36, "H1": 37, "T2": 38, "H2": 39,
}
n2s = {}
frequence = s2n.copy()
for key in s2n.keys():
    n2s[s2n[key]] = key
    frequence[key] = 0
CCSET = {2, 17, 33}
CHSET = {7, 22, 36}
CHPOS = 0
CCPOS = 0
CHLIST = [i + 1 for i in range(16)]
random.shuffle(CHLIST)
print(f'CHLIST:{CHLIST}')
CCLIST = [i + 1 for i in range(16)]
random.shuffle(CCLIST)
print(f'CCLIST:{CCLIST}')

if __name__ == '__main__':
    currentPOS = 0
    e = 0
    epochs = 2000000
    consecutiveDoubles = 0
    while e < epochs:
        dice1 = random.randint(1, 4)
        dice2 = random.randint(1, 4)
        currentPOS = (currentPOS + dice1 + dice2) % 40
        # print(f'i got {dice1} + {dice2} = {dice1 + dice2},  ', end='')
        if dice1 == dice2:
            consecutiveDoubles += 1
        else:
            consecutiveDoubles = 0
        if consecutiveDoubles % 3 == 0 and consecutiveDoubles != 0:
            currentPOS = 10
        if n2s[currentPOS] == "G2J":
            currentPOS = s2n['JAIL']
        elif currentPOS in CCSET:
            # print(f'i draw {CCLIST[CCPOS]} from CCLIST, ', end='')
            if CCLIST[CCPOS] == 1:
                currentPOS = s2n["GO"]
            elif CCLIST[CCPOS] == 2:
                currentPOS = s2n['JAIL']
            # print(f'and go to {n2s[currentPOS]}, ', end='')
            CCPOS = (CCPOS + 1) % 16
        elif currentPOS in CHSET:
            # print(f'i draw {CHLIST[CHPOS]} from CHLIST, ', end='')
            if CHLIST[CHPOS] == 1:
                currentPOS = s2n['GO']
            elif CHLIST[CHPOS] == 2:
                currentPOS = s2n['JAIL']
            elif CHLIST[CHPOS] == 3:
                currentPOS = s2n['C1']
            elif CHLIST[CHPOS] == 4:
                currentPOS = s2n['E3']
            elif CHLIST[CHPOS] == 5:
                currentPOS = s2n['H2']
            elif CHLIST[CHPOS] == 6:
                currentPOS = s2n['R1']
            elif CHLIST[CHPOS] == 7 or CHLIST[CHPOS] == 8:
                while 'R' not in n2s[currentPOS]:
                    currentPOS = (currentPOS + 1) % 40
            elif CHLIST[CHPOS] == 9:
                while 'U' not in n2s[currentPOS]:
                    currentPOS = (currentPOS + 1) % 40
            elif CHLIST[CHPOS] == 10:
                currentPOS -= 3
                # get 10 at 36, land on 33 and get the CC card
                if currentPOS == 33:
                    if CCLIST[CCPOS] == 1:
                        currentPOS = s2n["GO"]
                    elif CCLIST[CCPOS] == 2:
                        currentPOS = s2n['JAIL']
                    CCPOS = (CCPOS + 1) % 16
            # print(f'and go to {n2s[currentPOS]}, ', end='')
            CHPOS = (CHPOS + 1) % 16
        # print(f'finally go to {n2s[currentPOS]}', end='')
        # input()
        frequence[n2s[currentPOS]] += 1
        e += 1
    sorted_squares = sorted(frequence.items(), key=lambda x: x[1], reverse=True)
    print(sorted_squares[:6])
