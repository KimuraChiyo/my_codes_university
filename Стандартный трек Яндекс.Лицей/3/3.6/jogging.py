def jogging(time, speed=0, kkal=0, reduce=0):
    km = (time * 60 * speed) // 1000
    elapsed = km * kkal
    return elapsed, elapsed >= reduce

workout_time = 15
print(jogging(workout_time, speed=2,
              reduce=800,
              kkal=80))