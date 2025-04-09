class SortedStack:

    def __init__(self):
        self.st = []  # decreasing
        self.ot = []  # increasing

    def push(self, val: int) -> None:
        while self.st and self.st[-1] < val:
            self.ot.append(self.st[-1])
            self.st.pop()
        self.st.append(val)
        while self.ot and self.ot[-1] < self.st[-1]:
            self.st.append(self.ot[-1])
            self.ot.pop()
        # self.ot should have no elements

    def pop(self) -> None:
        if self.st:
            self.st.pop()

    def peek(self) -> int:
        return self.st[-1] if self.st else -1

    def isEmpty(self) -> bool:
        return not self.st
