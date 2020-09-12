import datetime
def solution(play_time, adv_time, logs):
    answer = ''

    markers = {}

    for log in logs:
        se = log.split("-")
        se[0] = datetime.datetime.strptime(se[0], "%H:%M:%S")
        se[1] = datetime.datetime.strptime(se[1], "%H:%M:%S")
        if se[0] in markers.keys():
            markers[se[0]] += 1
        else:
            markers[se[0]] = 1
        if se[1] in markers.keys():
            markers[se[1]] -= 1
        else:
            markers[se[1]] = -1
    markers = dict(sorted(markers.items()))

    sTime = list(markers.keys())[0]
    adv_time = adv_time.split(":")
    adv_timedelta = datetime.timedelta(hours=int(adv_time[0]),minutes=int(adv_time[1]),seconds=int(adv_time[2]))
    play_time = datetime.datetime.strptime(play_time,"%H:%M:%S")
    cur = 0
    keys = list(markers.keys())
    while sTime + adv_timedelta < play_time:
        if sTime in keys:
            cur += markers[sTime]
        tCur = cur
        nextMarker = keys[keys.index(sTime) + 1]
        while nextMarker < sTime + adv_timedelta:
            nextMarker = keys[keys.index(sTime)+1]




        sTime += datetime.timedelta(seconds=1)

    return answer




play_time,adv_time, logs = "02:03:55", "00:14:15", ["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]
print(solution(play_time,adv_time,logs))