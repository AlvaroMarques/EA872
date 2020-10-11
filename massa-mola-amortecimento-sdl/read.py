import matplotlib.pyplot as plt
x = []
while True:
    try:
        x.append(int(input()))
    except EOFError:
        break
plt.plot(x)
plt.show()
