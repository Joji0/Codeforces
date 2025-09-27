t = int(input())
for test in range(t):
    n, k = map(int, input().split())
    s = input()
    freq = {}
    for ch in s:
        if ch in freq:
            freq[ch] += 1
        else:
            freq[ch] = 1
    ok = True
    cntodd = 0
    over = 0
    for ch, cnt in freq.items():
        if cnt % 2:
            cntodd += cnt
            if k - 1 >= 0:
                k -= 1
            else:
                over += 1
    if over > 1:
        ok = False
    if ok:
        print("YES")
    else:
        print("NO")