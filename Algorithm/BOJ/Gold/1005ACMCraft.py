import sys

sys.stdin = open('1005.txt')

T = int(input())

for tc in range(1,T+1):
    N,K = map(int, sys.stdin.readline().split())
    D = [0]+list(map(int, sys.stdin.readline().split()))

    gunmul = [[0 for _ in range(N+1)] for _ in range(N+1)]
    for _ in range(K):
        X,Y = map(int, sys.stdin.readline().split())
        gunmul[X][Y] = 1
    W = int(input())

    bulid = [0 for _ in range(N+1)]
    time = [0 for _ in range(N+1)]
    for _ in range(N):
        ing = -1
        for i in range(1,N+1):
            flag = 1
            if bulid[i] == 0: # 안지어진 건물 중에
                for j in range(1,N+1):
                    if i == j : continue
                    if gunmul[j][i] == 0 : continue
                    if not (gunmul[j][i] and bulid[j] ):
                        flag =0
                        break
            else:
                continue
            if flag:
                ing = i
                break
        bulid[ing] = 1

        b_time = 0
        for k in range(1,N+1):
            if gunmul[k][i] and bulid[k]:
                if b_time < time[k]:
                    b_time = time[k]
        b_time += D[ing]
        time[ing] = b_time
        if ing == W:
            print(time[ing])
            break
