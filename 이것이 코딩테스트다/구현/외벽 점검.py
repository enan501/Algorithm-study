def solution(n, weak, dist):
    answer = -1
    dist.sort(reverse=True)
    for friends in range(1, len(dist)+1):
        selected_dists = dist[:friends]

        for start_weak in range(len(weak)):
            cnt = 0
            cur_weak = start_weak

            for selected_dist in selected_dists:
                cnt += get_count(weak, cur_weak, selected_dist)
                cur_weak = (cur_weak + selected_dist) % n

            if cnt >= n:
                answer = friends
                return answer

    return answer

def get_count(weak, cur_weak, dist): # cnt += weak[0] ~ selected_dist[0] 안에 들어있는 weak 수
    cnt = 0
    cur_weak_index = weak.index(cur_weak)
    return cnt

n = 12
weak = [1, 5, 6, 10]
dist = [1, 2, 3, 4]
print(solution(n,weak,dist))