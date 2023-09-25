count_of_strings = int(input())

dictionary_colors = {}

for i in range(count_of_strings):
    string = list(map(int, input().replace('\t', ' ').split()))
    color_curr_str = [f'{str(string[i])} {str(string[i + 1])} {str(string[i + 2])}' for i in range(0, len(string), 3)]
    for color in color_curr_str:
        dictionary_colors[color] = dictionary_colors.get(color, 0) + 1
mx = max(dictionary_colors.values())
print(*sorted([key for key in dictionary_colors.keys() if dictionary_colors[key] == mx]), sep='\n')