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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,x,k,n=0;cin>>t;
    while(t--){
        n++;
        int res=0;
        cin>>x>>k;
        for(int i=1; i<=x; i++){
            res=(res+k)%i;
        }
        res++;
        cout<<"Case "<<n<<": "<<res<<endl;
    }
}