import heapq
import sys

old_depth = sys.getrecursionlimit()
new_depth = 82630
sys.setrecursionlimit(new_depth)
print(f"old:{old_depth}, new: {sys.getrecursionlimit()}")


class Solution:

    def mostCompetitive0(self, nums, k):
        # 应当使用贪心策略
        if k == 0:
            return []
        h = []
        n = len(nums)
        for i, num in enumerate(nums):
            heapq.heappush(h, (num, i))
        num, i = h[0]
        while h and i + k > n:
            heapq.heappop(h)
            num, i = h[0]
        return [num] + self.mostCompetitive0(nums[i + 1 :], k - 1)

    def find_seq(self, n, k, pos, h):
        if k == 0:
            return []

        while h and pos[h[0]][0] + k > n:
            if len(pos[h[0]]) == 1:
                del pos[h[0]]
                heapq.heappop(h)
            else:
                pos[h[0]] = pos[h[0]][1:]
        # if not h:
        #     return []

        start, i = h[0], pos[h[0]][0]

        # 选择了start后，将pos中小于其位置的都删除
        for num in h:
            while len(pos[num]) > 0 and pos[num][0] <= i:
                pos[num] = pos[num][1:]
            if len(pos[num]) == 0:
                del pos[num]

        # print(f"Found start {start}, pos: {pos}, nums: {nums}")
        return [start] + self.find_seq(n, k - 1, pos, h)

    def find_seq_n_recurve(self,n,k,pos,h):
        ret=[]
        for ki in range(k):
            while h and pos[h[0]][0]+k-ki>n:
                if len(pos[h[0]]) == 1:
                    del pos[h[0]]
                    h = h[1:]
                else:
                    pos[h[0]] = pos[h[0]][1:]
            start,i=h[0],pos[h][0]
            ret.append(start)
            for num in h:
                while len(pos[num]) > 0 and pos[num][0] <= i:
                    pos[num] = pos[num][1:]
                if len(pos[num]) == 0:
                    del pos[num]

    def mostCompetitive1(self, nums, k):
        pos = {}
        for i, num in enumerate(nums):
            if num not in pos:
                pos[num] = [i]
            else:
                pos[num].append(i)
        
        h =[]
        for k in pos.keys():
            heapq.heappush(h,k)
        # for num in h:
        #     print(f"k={num},v={len(pos[num])}")
        # exit()
        return self.find_seq(len(nums), k, pos, h)

    def mostCompetitive2(self, nums, k):
        st=[]
        for i,num in enumerate(nums):
            while st and st[-1][0]>num:
                st.pop()
            st.append([num,i])
        ori_k=k
        n=len(nums)
        ret=[]
        for num,i in st:
            if i+k<=n:
                ret.append(num)
                k-=1
                if len(ret)>=ori_k:
                    break
        return ret

    def mostCompetitive3(self, nums, k):
        members=[]
        for i,num in enumerate(nums):
            members.append([num,i])
        members=sorted(members,key=lambda x:x[0])
        ori_k=k
        n=len(nums)
        cur_start=0
        ret=[]
        for num,i in members:
            if i>=cur_start and i+k<=n:
                cur_start=i+1
                ret.append(num)
                k-=1
                if len(ret)>=ori_k:
                    break
        while len(ret)<ori_k:
            ret.append(nums[cur_start])
            cur_start+=1
        return ret
    def mostCompetitive(self, nums, k):
        st=[]
        for i,num in enumerate(nums):
            while st and st[-1]>num and len(st)+len(nums)-i>k:
                st.pop()
            if len(st)<k:
                st.append(num)
        return st

if __name__ == "__main__":
    s = Solution()
    nums = [84,10,71,23,66,61,62,64,34,41,80,25,91,43,4,75,65,13,37,41,46,90,55,8,85,61,95,71]
    k = 24
    ans=s.mostCompetitive(nums, k)
    print(ans)
