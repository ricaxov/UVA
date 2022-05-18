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
    int n; cin>>n;
    while(n!=0){
        int soma=0,ans=0;
        vector<int>vec(n);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }
        for(int i=0; i<n; i++){
            soma+=vec[i];
            ans=max(ans, soma);
            if(soma<0){
                soma=0;
            }
        } 
        if(ans<=0){
            cout<<"Losing streak."<<endl;
        }
        else{
            cout<<"The maximum winning streak is "<<ans<<"."<<endl;    
        }
        cin>>n;
    }
}
