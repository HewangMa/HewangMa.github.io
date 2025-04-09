def demo1():
    """
    for循环测试
    :return: None
    """
    money = 10000
    for i in range(1, 21):
        import random
        score = random.randint(1, 10)
        if score < 5:
            print(f"员工{i}绩效不符，不发工资")
        elif money >= 1000:
            money -= 1000
            print(f"给员工{i}发工资1000元")
        else:
            print("工资发完啦")
            break
    return None


def demo2():
    """
    list测试
    :return: None
    """
    Mlist = ["one", "two", "three"]
    index = 0
    while index < len(Mlist):
        print(Mlist[index])
        index += 1
    return None


def demo3():
    """
    tuple测试
    :return:
    """
    t2 = ("mahewang", 24, 174)
    print(f"t2的类型是：{type(t2)},内容是：{t2}")
    # print(f"姓名： {t2[0]} ({type(t2[0])}) 年龄：{t2[1]}  身高：{t2[2]}")
    return None


class Solution(object):
    def minScoreTriangulation(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        n = len(values)

        if n == 3:
            return values[0] * values[1] * values[2]

        b = values[-1]
        c = values[-2]
        ans1 = values[0] * b * c + self.minScoreTriangulation(values[0:-1])
        ans2 = b * c * values[-3] + self.minScoreTriangulation(values[:-3].append(b))

        ans = min(ans1, ans2)

        for index in range(1, n - 3):
            temp = values[index] * b * c
            p1 = self.minScoreTriangulation(values[0:index + 1].append(b))
            p2 = self.minScoreTriangulation(values[index:-1])
            ans = min(ans, temp + p1 + p2)

        return ans


def demo4():
    """dict 测试"""
    employee_dict = {
        "zhou": {
            "级别": 2,
            "工资": 4000,
            "部门": "技术部"
        },
        "liu": {
            "级别": 5,
            "工资": 6000,
            "部门": "技术部"
        },
        "de": {
            "级别": 2,
            "工资": 4000,
            "部门": "市场部"
        }
    }

    for name in employee_dict:
        if employee_dict[name]["级别"] == 2:
            employee_dict[name]["级别"] = 3
            employee_dict[name]["工资"] += 1300

    print(employee_dict)
