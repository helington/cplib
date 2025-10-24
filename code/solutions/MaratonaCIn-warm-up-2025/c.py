def main():
    s = input().split("|")

    s.pop()
    s.pop(0)

    lenghts = ""
    for i in range(len(s)):
        lenght = str(len(s[i]))
        lenghts += f"{lenght} " if i < len(s) - 1 else lenght
    
    print(lenghts)
    
main()