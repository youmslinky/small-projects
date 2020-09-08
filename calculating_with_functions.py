from functools import partial


def zero(*args):
    if len(args) == 0:
        return 0
    return args[0](0)


def one(*args):
    if len(args) == 0:
        return 1
    return args[0](1)


def two(*args):
    if len(args) == 0:
        return 2
    return args[0](2)


def three(*args):
    if len(args) == 0:
        return 3
    return args[0](3)


def four(*args):
    if len(args) == 0:
        return 4
    return args[0](4)


def five(*args):
    if len(args) == 0:
        return 5
    return args[0](5)


def six(*args):
    if len(args) == 0:
        return 6
    return args[0](6)


def seven(*args):
    if len(args) == 0:
        return 7
    return args[0](7)


def eight(*args):
    if len(args) == 0:
        return 8
    return args[0](7)


def nine(*args):
    if len(args) == 0:
        return 9
    return args[0](9)


def plus(*args):
    if len(args) == 1:
        return partial(plus, args[0])
    return args[0] + args[1]


def minus(*args):
    if len(args) == 1:
        return partial(minus, args[0])
    return args[1] - args[0]


def times(*args):
    if len(args) == 1:
        return partial(times, args[0])
    return args[1] * args[0]


def divided_by(*args):
    if len(args) == 1:
        return partial(divided_by, args[0])
    return args[1] // args[0]
