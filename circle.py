import random as r
import math as m
#bool(r.getrandbits(1))
#r.uniform(-1,1)
def crossProduct(a,b):
	#a and b are R^3
	# c=[]
	# c.append(a[1]*b[2]-a[2]*b[1])
	# c.append(-(a[0]*b[2]-a[2]*b[0]))
	# c.append(a[0]*b[1]-a[1]*b[0])
	return [a[1]*b[2]-a[2]*b[1], -(a[0]*b[2]-a[2]*b[0]), a[0]*b[1]-a[1]*b[0]]

def dotProduct(a,b):
	return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]

def vecSub(a,b):
	# a and b are R^3
	return [a[0]-b[0],a[1]-b[1],a[2]-b[2]]

def sameSide(p1,p2, a,b):
	#checks if p1 and p2 are on the same side of the line a-b
	cp1=crossProduct(vecSub(b,a), vecSub(p1,a))
	cp2=crossProduct(vecSub(b,a), vecSub(p2,a))
	if dotProduct(cp1,cp2) >= 0:
		return True
	else:
		return False

def pointInTriangle(p, a,b,c):
	# checks if point p is within triangle a-b-c
	# all points are R^3
	if sameSide(p,a, b,c) and sameSide(p,b, a,c) and sameSide(p,c, a,b):
		return True
	else:
		return False
def pickPoints():
	points=[]
	for i in range(3):
		
		x=r.uniform(-1,1)
		y=m.sqrt(1-m.pow(x,2))
		if bool(r.getrandbits(1)):
			y*=-1
		points.append([x,y,0])
	return points


# pointsIn = 0
# pointsTotal = 10000
# for i in range(pointsTotal):
# 	points = pickPoints()
# 	if pointInTriangle([0,0,0], points[0],points[1],points[2]):
# 		pointsIn += 1
# print 'points in:',pointsIn
# print 'fraction in',float(pointsIn)/pointsTotal
f = open('circle.csv','wb')
pointsIn = 0
pointsTotal = 0
while pointsTotal < 100000:
	points = pickPoints()
	pointsTotal += 1
	if pointInTriangle([0,0,0], points[0],points[1],points[2]):
		pointsIn += 1
	if pointsTotal % 10 == 0:
		print(('points in:',pointsIn))
		print(('points total',pointsTotal))
		print(('fraction in',float(pointsIn)/pointsTotal))
		f.write("%d,%d\n" % (pointsIn,pointsTotal))

f.close()