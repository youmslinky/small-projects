#! /usr/bin/python
while 1==1:
	
	totalSeconds = eval(input("number of seconds:"))
	
	hours = totalSeconds // 3600  
	
	seconds = totalSeconds % 3600
	
	minutes = seconds // 60
	
	seconds = seconds % 60
	
	
	print(( str(totalSeconds) + ' seconds is ' + str(hours) + ' hours, ' + str(minutes) + ' minutes, and ' + str(seconds) + ' seconds.'))
