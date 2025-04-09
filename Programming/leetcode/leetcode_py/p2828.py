class Solution:
    def isAcronym(self, words, s):
        first_letters = [word[0] for word in words]
        acr = "".join(first_letters)
        return acr == s
