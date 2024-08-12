#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ld long double
#define ll long long
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fastio()    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); cout.tie(NULL); \
//
void io(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
//
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef pair<ull,ull> pull;
typedef pair<ll,ll> pll;


//code here
int main(){
    fastio(); //io();
    ull n,m,q,num,x1,y1,x2,y2,sum;
    cin>>n>>m>>q;
    ull mtrx[n][m+1];
    rep(i,0,n){
        sum=0;
        rep(j,0,m+1){
            if(j==0) mtrx[i][j]=0;
            else{
                cin>>num; sum+=num;
                mtrx[i][j]=sum;
            }
        }
    }
    /*
    rep(i,0,n){
        rep(j,1,m+1){
            cout<<mtrx[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    rep(i,0,q){
        sum=0;
        cin>>x1>>y1>>x2>>y2;
        rep(j,x1-1,x2){
            sum+=mtrx[j][y2]-mtrx[j][y1-1];
        }
        cout<<sum<<'\n';
    }
    return 0;
}