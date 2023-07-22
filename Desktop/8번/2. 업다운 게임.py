import random

# 랜덤 숫자 생성
number = random.randint(1, 20)

# 게임 시작
print("숫자를 맞춰보세요.")

# 3번의 기회
for i in range(3):
    # 사용자 입력
    guess = int(input())

    # 숫자 비교
    if guess > number:
        print("UP")
    elif guess < number:
        print("DOWN")
    else:
        print("정답입니다!")
        break

# 3번 안에 못 맞추면 실패
if i == 2:
    print("실패입니다.")