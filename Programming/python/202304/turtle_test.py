# 此文件用以创建文件接口自动绘制图形
import turtle as t


def test01():
    t.title("自动轨迹绘制")
    t.setup(800, 800, 100, 100)
    t.color("red")
    t.pensize(5)

    il = []
    file = open("turtle_test_data.txt", "r+", encoding="utf-8")
    file.write("300,0,144,1,0,0\n")
    file.write("300,0,144,0,1,0\n")
    file.write("300,0,144,0,0,1\n")
    file.write("300,0,144,1,1,0\n")
    file.write("300,0,144,0,1,1\n")
    file.seek(0)
    for line in file:
        line = line.replace("\n", "")  # 要记得删除末尾的回车
        il.append(list(map(eval, line.split(","))))
    file.close()

    for i in range(len(il)):
        t.pencolor(il[i][3], il[i][4], il[i][5])
        t.fd(il[i][0])
        if il[i][1] == 1:
            t.right(il[i][2])
        else:
            t.left(il[i][2])

    t.done()

if __name__ == '__main__':
    test01()
