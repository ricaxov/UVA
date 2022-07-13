def main():
    while True:
        try:
            soma=0
            ans=-100000
            x=list(map(int, input().split()))
            for i in range(len(x)):
                soma+=x[i]
                ans=max(ans,soma)
                if soma<0:
                    soma=0
            if ans<0:
                ans=0
            print(ans)
        except EOFError:
            break
if __name__=="__main__":
    main()
