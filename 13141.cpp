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

vector<ll>dp(100000);
ll fib(ll x){
    if(x<3) return 1;
    if(dp[x]!=0) return dp[x];
    return dp[x]=fib(x-1)+fib(x-2);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n; cin>>n;
    while(n!=0){
        cout<<fib(n)<<endl;
        cin>>n;
    }
}
