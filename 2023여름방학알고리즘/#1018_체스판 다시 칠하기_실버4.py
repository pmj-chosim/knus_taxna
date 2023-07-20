def count_repainting(board, start_row, start_col):
    count1, count2 = 0, 0
    for i in range(8):
        for j in range(8):
            if (i + j) % 2 == 0:  # 짝수번째 칸
                if board[start_row + i][start_col + j] != 'W':
                    count1 += 1
                if board[start_row + i][start_col + j] != 'B':
                    count2 += 1
            else:  # 홀수번째 칸
                if board[start_row + i][start_col + j] != 'B':
                    count1 += 1
                if board[start_row + i][start_col + j] != 'W':
                    count2 += 1
    return min(count1, count2)

def min_repainting(board):
    n, m = len(board), len(board[0])
    min_repainting = float('inf')
    for i in range(n - 7):
        for j in range(m - 7):
            min_repainting = min(min_repainting, count_repainting(board, i, j))
    return min_repainting

'''시작'''
n, m = map(int, input().split())
board = [input() for _ in range(n)]

# wBWB로 시작하는 체스판의 경우
min_wBWB = min_repainting(board)

# BWBW로 시작하는 체스판의 경우
for i in range(n):
    board[i] = board[i].replace('W', 'X').replace('B', 'W').replace('X', 'B')
min_BWBW = min_repainting(board)

# 두 경우 중 최솟값 출력
print(min(min_wBWB, min_BWBW))