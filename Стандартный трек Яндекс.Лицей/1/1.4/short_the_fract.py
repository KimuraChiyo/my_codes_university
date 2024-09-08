# func for k for shorten the fract
def nod(a, b):
    while a != b:
        if b > a:
            b -= a
        else:
            a -= b
    return a


# in
a, b, c, d = int(input()), int(input()), int(input()), int(input())

# to overall znam
overall_znam = b * d
a *= d
c *= b

# find overall chisl
overall_chisl = 0
if c > a:
    overall_chisl = c - a
elif c < a:
    overall_chisl = a - c

# to unshorten fraction
nod = nod(overall_znam, overall_chisl)
overall_znam = overall_znam // nod
overall_chisl = overall_chisl // nod

# out
print(overall_chisl, overall_znam, sep='/')
