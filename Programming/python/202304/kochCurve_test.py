# 该py文件用于绘制科赫雪花曲线
import turtle as t


def koch(size, n):
    if n == 0:
        t.fd(size)
    else:
        koch(size / 3, n - 1)
        t.left(60)
        koch(size / 3, n - 1)
        t.right(120)
        koch(size / 3, n - 1)
        t.left(60)
        koch(size / 3, n - 1)


def test01():
    t.penup()
    t.speed(200)
    t.hideturtle()
    t.fd(-500)
    t.pendown()
    koch(900, 5)
    t.done()


if __name__ == '__main__':
    test01()
