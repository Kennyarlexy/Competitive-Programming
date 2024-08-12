# include <bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fastio()      \
 ios_base::sync_with_stdio(false); \
 cin.tie(NULL); cout.tie(NULL);  \

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
//
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
//
typedef vector<string> vs;
typedef pair<string, string> pss;
typedef pair<string, ll> psl;
typedef vector<psl> vsl;
typedef vector<pss> vss;
//
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007

int main(){
 fastio();
 ll t, n, a, b, c;
 string s, str;

 // masukan banyak sisik
 cin >> n;
 // penyimpanan semua sisik
 set<ll> A;

 // counter setiap bilangan sisik 
 ll counter[10003];
 // inisialisasi setiap sisik berjumlah 0
 memset(counter, 0, sizeof(counter));
 // penyimpanan ganjil dan genap
 list<ll> ganjil, genap;


 REP(i,0,n){
    // masukan a
    cin >> a;
    // hitung kemunculan a
    counter[a]++;
    // masukan a ke set
    A.insert(a);
 }

 for (auto i: A){
    if (counter[i] >= 2){
        // pass;
    }
    else if (i%2 == 1){
        // masukan bilangan ganjil
        ganjil.PB(i);
    }
    else {
        // masukan bilangan genap
        genap.PB(i);
    }
 }

 bool flag_output = false;

 while (!(ganjil.empty() and genap.empty())) {
    if (!ganjil.empty()){
        cout << ganjil.front() << " ";
        ganjil.pop_front();
    }
    if (!genap.empty()){
        cout << genap.front() << " ";
        genap.pop_front();
    }
    flag_output = true;
 }

 if (flag_output){
    cout << endl;
 }

 return 0;
}