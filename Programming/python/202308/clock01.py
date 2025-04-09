"""亦称为七段数码管显示日期"""

import turtle as t
import time


def drawGap():
    t.penup()
    t.fd(6)


def drawLine(draw):
    drawGap()
    t.pendown() if draw else t.penup()
    t.fd(40)
    drawGap()
    t.right(90)


def drawDigit(digit):
    drawLine(True) if digit in [2, 3, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 1, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 3, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 6, 8] else drawLine(False)
    t.left(90)
    drawLine(True) if digit in [0, 4, 5, 6, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 2, 3, 5, 6, 7, 8, 9] else drawLine(False)
    drawLine(True) if digit in [0, 1, 2, 3, 4, 7, 8, 9] else drawLine(False)
    t.left(180)
    t.penup()
    t.fd(25)


def drawDate(str):
    """%Y+%M-%D*"""
    t.color("red")
    for i in str:
        if i == "+":
            t.write("时", font=("Arial", 40, "normal"))
            t.fd(80)
            t.color("green")
        elif i == "-":
            t.write("分", font=("Arial", 40, "normal"))
            t.fd(80)
            t.color("blue")
        elif i == "*":
            t.write("秒", font=("Arial", 40, "normal"))
            t.fd(80)
        else:
            drawDigit(eval(i))


def test_001():
    t.setup(800, 800, 100, 100)
    t.penup()
    t.bk(300)
    t.pensize(5)
    t.pencolor("purple")
    t.speed(200)
    timestr = time.strftime("%H+%M-%S*", time.localtime())
    drawDate(timestr)
    t.hideturtle()
    t.done()


if __name__ == "__main__":
    test_001()
