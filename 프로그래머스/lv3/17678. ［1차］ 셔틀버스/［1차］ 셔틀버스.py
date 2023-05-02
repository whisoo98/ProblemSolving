def solution(n, t, m, timetable):
    arrivedAt = [0 for _ in range(1500)]
    for times in timetable:
        hh, mm = map(int,times.split(":"))
        mm += hh * 60
        arrivedAt[mm]+=1
    
    bustable = []
    for i in range(n):
        bustable.append(9*60 + t*i)
        
    last_time = 0
    limit_passenger = m*n
    wait_passenger=0
    for tick in range(1440):
        wait_passenger += arrivedAt[tick]
        if wait_passenger>=limit_passenger:
            break
        else:
            last_time = tick
            if tick in bustable:
                limit_passenger -= m
                wait_passenger = max(0, wait_passenger - m)
        
    hh = last_time//60
    mm = last_time%60
    answer = "{0:0>2}:{1:0>2}".format(hh,mm)
    return answer