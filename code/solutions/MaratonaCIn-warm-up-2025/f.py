n, k = map(int, input().split())

a = list(map(int, input().split()))

total = 0
current_sum = 0
left = 0

for right in range(n):
    current_sum += a[right]
    while current_sum >= k and left <= right:
        total += (n - right)
        current_sum -= a[left]
        left += 1

print(total)