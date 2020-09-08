import random as r

pointTotal = 0
pointIn = 0
while True:
    if r.uniform(0, 1) ** 2 + r.uniform(0, 1) ** 2 <= 1:
        pointIn += 1
    pointTotal += 1
    if pointTotal % 100000 == 0:
        print((pointTotal, pointIn, float(pointIn) / pointTotal * 4))
