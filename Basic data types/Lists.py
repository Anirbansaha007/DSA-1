if __name__ == '__main__':
    N = int(input())
    l =[]
    for i in range(N):
        x = input().split()
        a = list(x)
        if a[0] == "insert":
            l.insert(int(a[1]),int(a[2]))
        if a[0] == "print":
            print(l)
        if a[0] == "append":
            l.append(int(a[1]))
        if a[0] == "sort":
            l.sort()
        if a[0] == "reverse":
            l.reverse()
        if a[0] == "pop":
            l.pop()
        if a[0] == "remove":
            l.remove(int(a[1]))