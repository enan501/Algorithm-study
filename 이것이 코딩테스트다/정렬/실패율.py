def solution(N, stages):
    fails, fail_rates = [0] * (N+1), [0] * N
    for stage in stages:
        fails[stage-1] += 1
    challengers = fails[N]
    for i in range(N - 1, -1, -1):
        challengers += fails[i]
        if challengers > 0:
            fail_rates[i] = fails[i] / challengers
    answer = list(map(lambda x:x[0]+1, sorted(enumerate(fail_rates),key=lambda x:(x[1]*-1,x[0]))))
    return answer

print(solution(15,[1,2,3,4,5,0,10]))