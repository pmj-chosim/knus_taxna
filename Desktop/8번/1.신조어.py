# Python 신조어/줄임말 퀴즈

# 환영인사
print("Python 신조어/줄임말 퀴즈를 시작합니다.")

# 취존
print("취존은 어떤 문장의 줄임말인가요?")
answer = input()
correct=0

# 입력받은 문장과 저장된 문장 비교
if answer == "취향존중":
  print("정답입니다!")
  correct+=1
else:
  print("오답입니다. 정답은 취향존중입니다.")

# 솔까말
print("솔까말은 어떤 문장의 줄임말인가요?")
answer = input()

# 입력받은 문장과 저장된 문장 비교
if answer == "솔직히 까놓고 말해":
  print("정답입니다!")
  correct+=1
else:
  print("오답입니다. 정답은 솔직히 까놓고 말해입니다.")

# 케바케
print("케바케는 어떤 문장의 줄임말인가요?")
answer = input()

# 입력받은 문장과 저장된 문장 비교
if answer == "경우에 따라 다르다":
  correct+=1
  print("정답입니다!")
else:
  print("오답입니다. 정답은 경우에 따라 다릅니다.")


print("3개 퀴즈 중 {}개 정답입니다.".format(correct))