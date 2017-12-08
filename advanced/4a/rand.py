import random

afile = open("random.txt", "w")

for i in range(15):
    line = ""
    x = random.randint(1, 100)
    afile.write(str(x))
    afile.write('\n')
    for k in range(x):
        line += str(random.randint(1, 1000000)) + " "
    afile.write(line)
    afile.write('\n')

afile.close()
