#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 1000000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

using namespace std;

int dp[27][27][352];
int f(int letter, int size, int sum){
    if(size==0){
        if(sum==0){
            return 1;
        }
        return 0;
    }
    if(letter>26 || size<0 || sum<0) return 0;
    if(dp[letter][size][sum]!=-1) return dp[letter][size][sum];
    int ans=0;
    for(int i=letter; i<=26; i++){
        ans+=f(i+1,size-1,sum-i);
    }
    return dp[letter][size][sum]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int l,s,v=1; cin>>l>>s;
    while(l!=0 || s!=0){
        memset(dp, -1, sizeof(dp));
        cout<<"Case "<<v++<<": ";
        if(l>26 || s>351){
            cout<<'0'<<endl;
        }
        else{
            cout<<f(1,l,s)<<endl;
        }
        cin>>l>>s;
    }
}
