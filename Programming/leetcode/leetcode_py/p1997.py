class Solution:
    def firstDayBeenInAllRooms(self, nextVisit):
        visit_time = {}
        n = len(nextVisit)
        room = 0
        day = 0
        magic = 1000000007
        while True:
            print(f"visit {room},time: {visit_time}")
            if room not in visit_time:
                visit_time[room] = 1
            else:
                visit_time[room] += 1
            if len(visit_time) == n:
                return day % magic
            day += 1
            if visit_time[room] % 2 == 1:
                room = nextVisit[room]
            else:
                room = (room + 1) % n


if __name__ == "__main__":
    nextVisit = [0, 0, 0, 0, 0]
    s = Solution()
    print(s.firstDayBeenInAllRooms(nextVisit))
