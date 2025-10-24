def main():
    n = int(input())

    maximum_expoent = 0
    current_expoent = 1
    while True:
        current_division = int(n / (5**current_expoent))
        if current_division == 0:
            break
        maximum_expoent += current_division
        current_expoent += 1
    
    print(maximum_expoent)

main()