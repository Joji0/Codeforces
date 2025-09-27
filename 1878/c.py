t = int(input())
for test in range(t):
    n, k, x = map(int, input().split())
    minn = k * (k + 1) / 2
    maxx = n * k - k * (k - 1) / 2
    if x >= minn and x <= maxx:
        print("YES")
    else:
        print("NO")