# 这个py文件用以统计一个文件的词频
import jieba


def getTxt(fname):
    txt = open(fname, "r", encoding="utf-8").read()
    txt = txt.lower()
    for i in "~!@#$%^&*()_+{}:123456789,./\|":
        txt.replace(i, " ")
    return txt


def test01():
    words = getTxt("hemingway_words_test.txt").split()
    counts = {}
    for word in words:
        counts[word] = counts.get(word, 0) + 1
    lt = list(counts.items())
    lt.sort(key=lambda x: x[1], reverse=True)
    for i in range(10):
        (word, count) = lt[i]
        print("{:<10}{}".format(word, count))


def test02():
    file = open("老人与海.txt", "r", encoding="utf-8").read()
    words = jieba.lcut(file)
    counts = {}
    for word in words:
        if len(word) == 1:
            continue
        else:
            counts[word] = counts.get(word, 0) + 1
    lt = list(counts.items())
    lt.sort(key=lambda x: x[1], reverse=True)
    for i in range(15):
        print("{:<10}{}".format(lt[i][0], lt[i][1]))
