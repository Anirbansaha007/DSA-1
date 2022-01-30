if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    a = list(arr)
    aa = sorted(a, reverse = True)
    for i in aa:
        if i != aa[0]:
            print(i)
            break