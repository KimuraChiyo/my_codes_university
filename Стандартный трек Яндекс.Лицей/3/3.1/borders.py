def borders(a, b, c):
    lefttop_x, lefttop_y = a
    rightbottom_x, rightbottom_y = b
    x, y = c
    if (x < lefttop_x or x > rightbottom_x) or (y > lefttop_y or y < rightbottom_y):
        flag = 'OUTSIDE'
    topbottom = (lefttop_x <= x <= rightbottom_x and (y == lefttop_y or y == rightbottom_y))
    leftright = (lefttop_y >= y >= rightbottom_y and (x == lefttop_x or x == rightbottom_x))
    if topbottom or leftright:
        flag = 'AT THE EDGE'
    if (lefttop_x < x < rightbottom_x) and (rightbottom_y < y < lefttop_y):
        flag = 'INSIDE'
    print(flag)

# borders((1, 3), (4, 0), (4, 4))
