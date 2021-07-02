
n = int(input())
t = []
w = []
ts = list(map(int,input().split()))
ws = list(map(int,input().split()))
mul =[]
for i in range(n):
    mul.append([ws[i]/ts[i], ws[i],ts[i]])

mul.sort(key = lambda x: x[1])

mul.sort(key = lambda x: x[0], reverse=True)





for i in range(1,n):
    mul[i][2]+=mul[i-1][2]

exhaustion = 0



for i in range(n):
    exhaustion+= mul[i][1]*mul[i][2]

print(exhaustion)
