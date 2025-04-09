class Solution:
    def p_stop_now(self, circle, land_pos, curr_profit, runningCost):
        tar = (land_pos + 3) % 4
        while circle[tar] == 0 and tar != land_pos:
            tar = (tar + 3) % 4
        return curr_profit - ((tar - land_pos + 4) % 4) * runningCost

    def rearrange(self, customers):
        save = 0
        for i, c in enumerate(customers):
            if c == 4:
                continue
            elif c > 4:
                save += c - 4
                customers[i] = 4
            else:
                need = 4 - c
                if save >= need:
                    customers[i] = 4
                    save -= need
                else:
                    customers[i] += save
                    save = 0
        while save > 0:
            arr = min(save, 4)
            customers.append(arr)
            save -= arr
        return customers

    def minOperationsMaxProfit(self, customers, boardingCost, runningCost):
        if 4 * boardingCost <= runningCost:
            return -1
        customers = self.rearrange(customers)
        print(f"cus: {customers}")

        circle = [0, 0, 0, 0]
        curr_profit = 0
        land_pos = 0
        ret = 0
        for i, num in enumerate(customers):

            # 不让这些人上了,也就是让上一轮的所有人都下来
            not_board = self.p_stop_now(circle, land_pos, curr_profit, runningCost)
            print(f"{i}th cus not board :{not_board}")
            ret = max(ret, not_board)

            # 让他们上
            board = min(4, num)
            curr_profit += boardingCost * board  # 收钱
            circle[land_pos] = board  # 上车

            curr_profit -= runningCost  # 运转
            land_pos = (land_pos + 1) % 4

        else:
            # 遍历完成后，要让所有人都下来, 额(⊙﹏⊙) 题目好像没有这样要求，算了
            all_board = self.p_stop_now(circle, land_pos, curr_profit, runningCost)
            print(f"all board :{all_board}")
            ret = max(ret, all_board)

        return ret


if __name__ == "__main__":
    cus = [8, 3]
    s = Solution()
    print(s.minOperationsMaxProfit(cus, 5, 6))
