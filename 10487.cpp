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
    int n,q,x,v=1; cin>>n;
    while(n!=0){
        vector<int>vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        cin>>q;
        int ans,atual=inf;
        cout<<"Case "<<v++<<":"<<endl;
        for(int i=0; i<q; i++){
            cin>>x;
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(j!=k){
                        ans=vec[j]+vec[k];
                        if(abs(ans-x)>abs(atual-x)){
                            ans=atual;
                        }
                        else{
                            atual=ans;
                        }
                    }
                }
            }
            cout<<"Closest sum to "<<x<<" is "<<ans<<"."<<endl;
        }
        cin>>n;
    }
}
