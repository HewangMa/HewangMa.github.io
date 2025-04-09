from pyecharts.charts import Line


def test():
    line = Line()
    line.add_xaxis(["小马", "小张"])
    line.add_yaxis("消费", [23, 45])
    line.render()


if __name__ == '__main__':
    test()
