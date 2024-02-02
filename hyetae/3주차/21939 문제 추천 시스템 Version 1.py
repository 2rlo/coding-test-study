# BOJ 21939 문제 추천 시스템 Version 1 https://www.acmicpc.net/problem/21939
# Created by 윤혜경 on 2/1/24.
import sys
import heapq

input = sys.stdin.readline

min_p = []
max_p = []
valid = [False for i in range(100001)]

N = int(input())
for _ in range(N):
    P, L = map(int, input().split())
    heapq.heappush(min_p, [L, P])
    heapq.heappush(max_p, [-L, -P])
    valid[P] = True

M = int(input())
for _ in range(M):
    cmd = input().split()
    if cmd[0] == "recommend":
        if cmd[1] == "1":
            while not valid[-max_p[0][1]]:
                heapq.heappop(max_p)
            print(-max_p[0][1])
        else:  # cmd[1] == "-1"
            while not valid[min_p[0][1]]:
                heapq.heappop(min_p)
            print(min_p[0][1])

    elif cmd[0] == "add":
        while not valid[-max_p[0][1]]:
            heapq.heappop(max_p)
        while not valid[min_p[0][1]]:
            heapq.heappop(min_p)
        heapq.heappush(min_p, [int(cmd[2]), int(cmd[1])])
        heapq.heappush(max_p, [-int(cmd[2]), -int(cmd[1])])
        valid[int(cmd[1])] = True

    else:  # solved
        valid[int(cmd[1])] = False
