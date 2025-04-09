class Solution:
    def maximumSumOfHeights0(self, maxHeights):
        n = len(maxHeights)
        dpl = [0 for _ in range(n)]
        dpr = [0 for _ in range(n)]
        # dpl[i] 表示以i为山峰时, i以及i左边的山峰高度和
        # dpr[i] 表示以i为山峰时, i以及i右边的山峰高度和
        dpl[0] = maxHeights[0]
        for i in range(1, n):
            mh = maxHeights[i]
            if mh >= maxHeights[i - 1]:
                dpl[i] = dpl[i - 1] + mh
            else:
                for k in range(i, -1, -1):
                    if maxHeights[k] >= mh:
                        dpl[i] += mh
                    else:
                        dpl[i] += dpl[k]
                        break
        dpr[n - 1] = maxHeights[n - 1]
        for i in range(n - 2, -1, -1):
            mh = maxHeights[i]
            if mh >= maxHeights[i + 1]:
                dpr[i] = dpr[i + 1] + mh
            else:
                for k in range(i, n):
                    if maxHeights[k] >= mh:
                        dpr[i] += mh
                    else:
                        dpr[i] += dpr[k]
                        break
        print(dpl)
        print(dpr)
        ret = 0
        for i in range(n):
            total_height = -maxHeights[i] + dpl[i] + dpr[i]
            ret = max(ret, total_height)
        return ret

    def maximumSumOfHeights(self, maxHeights):
        n = len(maxHeights)
        pre_st = []
        # stl[i] = (pos_height, pos, pre_total_height) 单调递增栈
        pre_h = [0 for _ in range(n)]
        for i in range(n):
            while pre_st and pre_st[-1][0] >= maxHeights[i]:
                pre_st.pop()
            if not pre_st:
                pre_st.append((maxHeights[i], i, (i + 1) * maxHeights[i]))
            else:
                pre_pos = pre_st[-1][1]
                pre_st.append(
                    (maxHeights[i], i, pre_st[-1][2] + (i - pre_pos) * maxHeights[i])
                )
            pre_h[i] = pre_st[-1][2]
        print(pre_h)

        post_st = []
        post_h = [0 for _ in range(n)]
        for i in range(n - 1, -1, -1):
            while post_st and post_st[-1][0] >= maxHeights[i]:
                post_st.pop()
            if not post_st:
                post_st.append((maxHeights[i], i, (n - i) * maxHeights[i]))
            else:
                post_pos = post_st[-1][1]
                post_st.append(
                    (maxHeights[i], i, post_st[-1][2] + (post_pos - i) * maxHeights[i])
                )
            post_h[i] = post_st[-1][2]
        print(post_h)
        ret = 0
        for i in range(n):
            ret = max(ret, pre_h[i] + post_h[i] - maxHeights[i])
        return ret
