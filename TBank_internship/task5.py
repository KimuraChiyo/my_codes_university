from copy import deepcopy

def seconds(time_str):
    h, m, s = map(int, time_str.split(':'))
    return h * 3600 + m * 60 + s

def get_queries(n, start_time):
    arr = []
    for i in range(n):
        query = input().split(' ')
        if query[3] != 'PONG':
            tfs = seconds(query[1]) - start_time
            if (tfs < 0): tfs += 24 * 60 * 60
            parsed = {
                'team': query[0],
                'tfs': tfs,
                'serv': query[2],
                'res': query[3]
            }
            arr.append(parsed)
    return arr

def processing(queries):
    teams_info = {}
    default_team_info = { 'count_hacked': 0, 'penalty': 0, 'servs_info': {} }
    default_serv_info = { 'is_hacked': 0, 'count_fails': 0 }
    for query in queries:
        curr_team = query['team']
        curr_serv = query['serv']
        curr_res = query['res']

        if query['team'] not in teams_info:
            teams_info[curr_team] = deepcopy(default_team_info)
        
        team_servs_info = teams_info[curr_team]['servs_info']
        if curr_serv not in team_servs_info:
            team_servs_info[curr_serv] = deepcopy(default_serv_info)

        curr_team_info = teams_info[curr_team]
        curr_serv_info = curr_team_info['servs_info'][curr_serv]
        if not teams_info[curr_team]['servs_info'][curr_serv]['is_hacked']:
            if curr_res == 'ACCESSED':
                curr_team_info['penalty'] = curr_serv_info['count_fails'] * 20 * 60 + query['tfs']
                curr_team_info['count_hacked'] += 1
                curr_serv_info['is_hacked'] = 1
            else:
                curr_serv_info['count_fails'] += 1

    return teams_info
        
def get_results(teams_info):
    arr = []
    for team_name in teams_info.keys():
        team_info = teams_info[team_name]
        team_count_hacked = team_info['count_hacked']
        team_penalty = team_info['penalty'] // 60
        arr.append([team_name, team_count_hacked, team_penalty])

    arr = sorted(arr, key=lambda x: (x[1], x[2], x[0]))

    place = 1
    same = 0
    last_team_name, last_team_count, last_team_penalty = arr[0]
    res_string = f'{place} {last_team_name} {last_team_count} {last_team_penalty}\n'
    for i in range(1, len(arr)):
        curr_team_name, curr_team_count, curr_team_penalty = arr[i]
        
        if last_team_count > curr_team_count or last_team_penalty < curr_team_penalty:
            place += same + 1
            same = 0
        else:
            same += 1

        last_team_name, last_team_count, last_team_penalty = arr[i]
        res_string += f'{place} {last_team_name} {last_team_count} {last_team_penalty}\n'
    return res_string


start_time = seconds(input())
n = int(input())
print(get_results(processing(get_queries(n, start_time))))

# 1 "T" 1 40
# 1 "YA" 1 40
# 3 "VK" 1 50
'''
00:00:00
5
"VK" 00:10:21 A FORBIDEN
"T" 00:00:23 A DENIED
"T" 00:20:23 A ACCESSED
"VK" 00:30:23 A ACCESSED
"YA" 00:40:23 B ACCESSED
'''

# 1 "Team1" 1 40
# 1 "Team2" 1 40
'''
01:00:00
3
"Team1" 01:10:00 A FORBIDEN
"Team1" 01:20:00 A ACCESSED
"Team2" 01:40:00 B ACCESSED
'''

# 1 "Team1" 1 60
'''
23:00:00
2
"Team1" 23:59:59 A PONG
"Team1" 00:00:00 A ACCESSED
'''