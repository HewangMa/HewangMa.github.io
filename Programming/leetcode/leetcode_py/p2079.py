class Solution:
    def wateringPlants(self, plants, capacity):
        n = len(plants)
        steps = 0
        pos = 0
        velum = capacity
        while pos < n:
            if velum >= plants[pos]:
                velum -= plants[pos]
                steps += 1
                # print(f"Finished plants[{pos}] of {plants[pos]},used steps {steps}")
                pos += 1
            else:
                steps += pos * 2
                velum = capacity
            # print(f"pos:{pos}, steps: {steps}, vel: {velum}")
        return steps


if __name__ == "__main__":
    plants = [2, 2, 3, 3]
    capacity = 5
    s = Solution()
    print(s.wateringPlants(plants, capacity))
