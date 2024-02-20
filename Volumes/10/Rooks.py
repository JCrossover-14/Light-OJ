
fact = [1]*31
for i in range(1,31):
    fact[i]=fact[i-1]*i
t = int(input())
for it in range(t):
    n,k = map(int,input().split())
    if k>n:
        print("Case "+str(it+1)+": 0")
    else:
        ans = fact[n]*fact[n]
        ans = ans/(fact[n-k]*fact[n-k]*fact[k])
        print("Case "+str(it+1)+": "+str(int(ans)))
    
