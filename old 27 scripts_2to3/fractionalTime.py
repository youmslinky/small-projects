#! /usr/bin/python
while 1==1:

        #input loop
        while 1==1:
                try:
                        totalHours = float(eval(input("Total Number of Hours: ")))
                except ValueError:
                        print("Not a float...")
                else:
                        break


	
        hours = int(totalHours)
	
        minutes = (totalHours - hours) * 60
	
        seconds = (minutes - int(minutes)) * 60

        minutes = int(minutes)

	
	
        print(( '  hours: '+str(hours) ))
        print(( 'minutes: '+str(minutes) ))
        print(( 'seconds: '+str(seconds) ))
