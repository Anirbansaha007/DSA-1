n = int(input())
l = []
for i in range(n):
    x = input()
    y = float(input())
    l.append([y,x])
    k = sorted(l)
    j = []
for i in k:
    if k[0][0] != i[0]:
        j.append(i)
# print(j)
for i in j:
    if j[0][0] == i[0]:
        print(i[1])