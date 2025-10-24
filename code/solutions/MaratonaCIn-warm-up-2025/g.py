def compute_coins(path_length, path):
    coins = 0
    for i in range(1, path_length):
        if i < path_length - 1 and path[i] == "*" and path[i + 1] == "*":
            return coins
        if path[i] == "@":
            coins += 1
    return coins

def main():
    t = int(input())

    for i in range(t):
        path_length = int(input())
        path = input()
        coins = compute_coins(path_length, path)
        print(coins)

main()