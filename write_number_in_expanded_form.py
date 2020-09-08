def expanded_form(n):
    zeros = ""
    nums = []
    for c in reversed(str(n)):
        if c != "0":
            nums.append(c + zeros)
        zeros += "0"
    return " + ".join(reversed(nums))


print(expanded_form(123048))
