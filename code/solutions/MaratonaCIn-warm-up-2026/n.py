def main():
    t = int(input())

    for _ in range(t):
        y, x = map(int,input().split())

        diagonal = 1

        if x == y:
            i = x - 1
            diagonal += int(2 * (( i * (i + 1)) / 2))
            print(diagonal)
        elif x > y:
            i = x - 1
            diagonal += int(2 * (( i * (i + 1)) / 2))
            
            if i % 2 == 0:
                print(diagonal + i - y + 1)
            else:
                print(diagonal - (i - y + 1))
        else:
            i = y - 1
            diagonal += int(2 * (( i * (i + 1)) / 2))
            
            if i % 2 == 0:
                print(diagonal - (i - x + 1))
            else:
                print(diagonal + i - x + 1)



main()