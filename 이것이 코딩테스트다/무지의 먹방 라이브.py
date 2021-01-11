from operator import itemgetter

# 1. 다 먹는데 걸리는 시간 순으로 정렬
# 2. 빨리 먹을 수 있는 음식부터 하나씩 다 먹음
# 3. 남은 시간 안에 다 먹을 수 있는 음식이 안 남으면 반복 종료
# 4. 남은 음식 중 몇 번째인지 계산

def solution(food_times: list, k: int):
    answer, cycle, left_time = -1, 0, k  # cycle: 현재까지 몇 바퀴 돌았는지
    food_times_indexed = sorted(enumerate(food_times), key=itemgetter(1))  # 원래 인덱스와 함께 정렬

    for order, food_time in enumerate(food_times_indexed):
        left_foods = len(food_times) - order
        eat_time = (food_time[1] - cycle) * left_foods  # 음식 하나 다 먹는 시간 = 그 음식의 남은 시간 * 남은 음식 수
        if eat_time > left_time:  # 다 먹을 수 있는 음식이 없으면
            left_food_times = sorted(food_times_indexed[order:], key=itemgetter(0))  # 남은 음식들 원래 인덱스 순으로 정렬
            last_food_index = left_time % left_foods # 남은 음식들 중 결국 k 번째에 먹는 음식
            answer = left_food_times[last_food_index][0] + 1  # 실제 인덱스 + 1
            break
        left_time -= eat_time
        cycle = food_time[1]

    return answer


if __name__ == "__main__":
    food_times = list(map(int, input().split()))
    k = int(input())
    print(solution(food_times, k))
