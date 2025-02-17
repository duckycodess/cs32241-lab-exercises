def fibs(n):
    ans = [0]
    first = 1
    second = 1
    for i in range(n-1):
        ans.append(first)
        temp = first + second
        first = second
        second = temp
    return ans if n else []

print(fibs(8))