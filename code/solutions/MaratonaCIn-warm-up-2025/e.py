def moves_increase_array(array, n):
    moves = 0
    for i in range(1, n):
        if array[i] < array[i - 1]:
            difference = array[i - 1] - array[i]
            moves += difference
            array[i] += difference
    
    return moves

def main():
    n = int(input())
    array = list(map(int, input().split()))

    moves = moves_increase_array(array, n)

    print(moves)
    
main()