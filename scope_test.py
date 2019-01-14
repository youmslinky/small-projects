def do_twice(func):
    def wrapper(*args,**kwargs):
        func(*args,**kwargs)
        func(*args,**kwargs)
    return wrapper

@do_twice
def say_hi():
    print('hi!')

@do_twice
def say_something(s):
    print(s)

say_something("hello there!",j='hi')
