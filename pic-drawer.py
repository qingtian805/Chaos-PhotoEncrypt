import matplotlib.pyplot as plt
import pandas


def draw_rand10000():
    fp = open("rand10000.csv", "r", encoding="utf-8")
    rands = pandas.read_csv(fp)

    plt.xlabel("time")
    plt.ylabel("float")

    plt.scatter(rands["time"], rands["float"])
    plt.show()

    plt.ylabel("internal")

    plt.scatter(rands["time"], rands["internal"])
    plt.show()

    fp.close()

def draw_functest():
    fp = open("functest.csv", "r", encoding="utf-8")

    rands = pandas.read_csv(fp)

    plt.xlabel("time")
    plt.ylabel("uchar")

    for i in ("1", "2", "3", "4", "5", "6", "7"):
        plt.scatter(rands["time"], rands[i])
        plt.show()

    fp.close()

draw_rand10000()
#draw_functest()