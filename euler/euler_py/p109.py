def compute():
    points = [i * j for i in range(1, 21) for j in range(1, 4)] + [25, 50]
    doublePoints = [i * 2 for i in range(1, 21)] + [50]
    ways = [[[None] * len(points) for _ in range(101)] for _ in range(3)]

    def cal(throw, total, maxIndex):
        if ways[throw][total][maxIndex] is None:
            if throw == 0:
                result = 1 if total == 0 else 0
            else:
                result = 0
                if maxIndex > 0:
                    result += cal(throw, total, maxIndex - 1)
                if points[maxIndex] <= total:
                    result += cal(throw - 1, total - points[maxIndex], maxIndex)
            ways[throw][total][maxIndex] = result
        return ways[throw][total][maxIndex]

    checkout = 0
    for remainingPoints in range(1, 100):
        for throw in range(3):
            for p in doublePoints:
                if p <= remainingPoints:
                    checkout += cal(throw, remainingPoints - p, len(points) - 1)

    return str(checkout)


if __name__ == '__main__':
    print(compute())
