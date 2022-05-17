while True:
    try:
        x=list(map(int, input().split()))
        res=-1000000
        for i in range(len(x)-1):
            ans=int(x[i])
            for j in range(i+1, len(x)-1):
                ans*=int(x[j])
                res=max(res, ans)
        print(max(res,ans))
    except EOFError:
        break
