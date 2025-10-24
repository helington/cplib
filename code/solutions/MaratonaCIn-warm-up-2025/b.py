def main():
    counter = 0
    for i in range(1, 13):
        s = input()
        if len(s) == i:
            counter += 1
    
    print(counter)

main()