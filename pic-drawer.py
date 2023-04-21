import matplotlib.pyplot as plt
import pandas

rands = pandas.read_csv("rand10000.csv")

print(rands["float"])

plt.xlabel("time")
plt.ylabel("float")

plt.figure(figsize=(1,2))

plt.scatter(rands["time"], rands["float"])
plt.show()

plt.ylabel("internal")

plt.scatter(rands["time"], rands["internal"])
plt.show()
