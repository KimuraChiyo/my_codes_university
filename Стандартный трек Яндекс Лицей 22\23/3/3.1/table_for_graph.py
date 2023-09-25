def graph(string):
    xs = ['x'] + [str(i) for i in range(-10, 11)]
    ys = ['y'] + [str(eval(string)) for x in range(-10, 11)]
    print('\t'.join(xs))
    print('\t'.join(ys))

# graph('x - 5')
