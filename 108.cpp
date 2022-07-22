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

int kadane(vector<int>vec, int n){
    int auxStart,start,finish=-inf,ans=-inf,soma=0;
    for(int i=0; i<n; i++){
        soma+=vec[i];
        if(soma<0){
            soma=0;
            auxStart=i+1;
        }
        else{
            if(soma>ans){
                ans=soma;
                start=auxStart;
                finish=i;
            }
        }
    }
    if(finish!=-inf) return ans;
    for(int i=0; i<n; i++){
        ans=max(ans,vec[i]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    while(cin>>n){
        int matrix[n][n],ans=-inf;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>matrix[i][j];
            }
        }
        vector<int>aux(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                aux[j]=0;
            }
            for(int j=i; j<n; j++){
                for(int k=0; k<n; k++){
                    aux[k]+=matrix[k][j];
                }
                ans=max(ans,kadane(aux,n));
            }
        }
        cout<<ans<<endl;
    }
}
