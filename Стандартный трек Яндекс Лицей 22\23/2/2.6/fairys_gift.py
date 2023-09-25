print('; '.join([('flower' if not i % 2 
                  else 'gemstone') for i in range(len(input().split(', ')))]))