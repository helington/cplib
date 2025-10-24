def solve(lines, n):
    for i in range(2, n):
        if lines[i - 1] + lines[i - 2] > lines[i]:
            return "YES"
    return "NO"

def main():
    n = int(input())
    lines = list(map(int, input().split()))
    lines = sorted(lines)

    answer = solve(lines, n)
    print(answer)
main()