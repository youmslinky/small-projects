# problem from mindyourdecisions youtube channel
# problem for 9 year old taiwan students

#  ABCDE
# x    A
# ------
# EEEEEE

#     DE
# x    A
#   ----
#    EEE


def solve_actual_problem():
    for a in range(1, 10):
        for b in range(10):
            for c in range(10):
                for d in range(10):
                    for e in range(1, 10):
                        a_s = str(a)
                        b_s = str(b)
                        c_s = str(c)
                        d_s = str(d)
                        e_s = str(e)

                        abcde = int(a_s + b_s + c_s + d_s + e_s)
                        eeeeee = int(e_s * 6)
                        if abcde * a == eeeeee:
                            print(f"a:{a} b:{b} c:{c} d:{d} e:{e}")
                            print(f"  {abcde}")
                            print(f" x    {a}")
                            print(" ------")
                            print(f" {eeeeee}")
                            print()


def solve_small_problem():
    for a in range(10):
        for d in range(10):
            for e in range(1, 10):
                # a_s = str(a)
                d_s = str(d)
                e_s = str(e)
                de = int(d_s + e_s)
                eee = int(e_s * 3)
                if de * a == eee:
                    print(f"a:{a} d:{d} e:{e}")
                    print(f"    {d}{e}")
                    print(f"x    {a}")
                    print("  ----")
                    print(f"   {eee:>3}")
                    print()


solve_actual_problem()
