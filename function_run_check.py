def func(val):
    print("func command run with val = {}".format(val))

def decider(run,function,val):
    if run:
        function(val)
    else:
        print("can't run that command")

decider(False,func,99)
