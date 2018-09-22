#!/usr/bin/python

import datetime

sub_loop = 1
loop = 1
choice = 1


while choice != 0:
    print()
    print("1) time for amount of resources")
    print("2) resources in amount of time")
    print("0) quit")
    choice = eval(input("what calulator would you like? "))
    if choice == 1:
        while choice == 1 or choice == 2:
            print("1) change all values")
            print("2) change current amount of resource")
            print("3) quit")
            choice = eval(input("what do you want to do? "))
            
            
            if choice == 1 or choice == 2:
                #at what time will there be enough resources?
                #how much time?
                if choice == 1:
                    production = float(eval(input("production of resource: ")))
                    target = eval(input("amount needed of resource: "))
                amount = eval(input("current amount of resource: "))
                print()
        
        
                hours = (target - amount) / production
        
        
                minutes = 60.0 * (hours - int(hours))
                seconds = str(int(60.0 * (minutes - int(minutes))))
                hours = str(int(hours))
                minutes = str(int(minutes))
        
                time = "    time needed:  H:" + hours + "  M:" + minutes + "  S:" + seconds
                print(time)
        
                seconds = int(seconds)
                minutes = int(minutes)
                hours = int(hours)
        
                now = datetime.datetime.now()
                hours = int(hours) + now.hour
                minutes = int(minutes) + now.minute
                seconds = int(seconds) + now.second
                minutes = minutes + seconds / 60
                hours = hours + minutes / 60
                seconds = str(seconds % 60)
                minutes = str(minutes % 60)
                hours = str(hours % 12)
                if int(hours) == 0:
                    hours = str(12)
                ETA = '    ETA:  ' + hours + ":" + minutes + ":" + seconds
                print(ETA)
                print()
    elif choice == 2:
        while choice == 1 or choice == 2:
        #work in progress, amount of resources per time
            print("1) change all values")
            print("2) change amount of time")
            print("3) quit")
            choice = eval(input("what do you want to do? "))
            
        
        
    
    
    
    
