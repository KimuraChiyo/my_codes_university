def defense(*points):
    xs, ys = [], []
    for tpl in points:
        x, y = tpl
        xs.append(x)
        ys.append(y)
    need = []
    need.append(abs(max(xs) - min(xs)))
    need.append(abs(max(ys) - min(ys)))
    return need