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

bool isprime(int x){
    if(x<2)
        return false;
    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<int>vec;
    for(int i=1; i<=35000; i++){
        if(isprime(i)){
            vec.pb(i);
        }
    }
    int n;cin>>n;
    while(n!=0){
        int x=0;
        for(int i=1; i<=n; i++){
            x=(x+vec[n-i])%i;
        }
        x++;
        cout<<x<<endl;
        cin>>n;
    }
}
