def is_leap_year(year):
    return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)

def weekDaysGen():
	while True:
		for i in ['mon','tue','wed','thu','fri','sat','sun']:
			yield i

def dateGen(endYear):
	weekDay=weekDaysGen()
	for year in range(1900,endYear+1):
		for month in range(1,13):
			if month in [1,3,5,7,8,10,12]:
				daysInMonth = 31
			elif month == 2:
				if is_leap_year(year):
					daysInMonth = 29
				else:
					daysInMonth = 28
			else:
				daysInMonth = 30
			for day in range(1,daysInMonth+1):
				yield [next(weekDay),day,month,year]

dates=dateGen(1900)

for date in dates:
	print(date)
	
dates=dateGen(2000)

sundays = 0
for date in dates:
	if date[0]=='sun' and date[1]==1 and date[3]>1900:
		sundays += 1

print(sundays)