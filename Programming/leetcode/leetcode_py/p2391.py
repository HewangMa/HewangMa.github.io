class Solution:
    def garbageCollection(self, garbage, travel):
        n = len(garbage)
        last_m_pos, last_g_pos, last_p_pos = n - 1, n - 1, n - 1
        while last_m_pos >= 0 and garbage[last_m_pos].count("M") == 0:
            last_m_pos -= 1
        while last_g_pos >= 0 and garbage[last_g_pos].count("G") == 0:
            last_g_pos -= 1
        while last_p_pos >= 0 and garbage[last_p_pos].count("P") == 0:
            last_p_pos -= 1
        m = (
            sum(g.count("M") for g in garbage) + sum(travel[:last_m_pos])
            if last_m_pos >= 0
            else 0
        )
        g = (
            sum(g.count("G") for g in garbage) + sum(travel[:last_g_pos])
            if last_g_pos >= 0
            else 0
        )
        p = (
            sum(g.count("P") for g in garbage) + sum(travel[:last_p_pos])
            if last_p_pos >= 0
            else 0
        )
        print(f"m: {m}, g: {g}, p: {p}")
        return m + g + p
