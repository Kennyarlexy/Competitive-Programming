#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree{
    private:
        vector<ll> st, lazy, arr;

    public:

        void build(ll p, ll L, ll R){
            if(L==R){
                st[p] = arr[L];
                return;
            }

            ll mid = (L+R)/2;
            build(p*2, L, mid);
            build(p*2+1, mid+1, R);
            st[p] = st[p*2] + st[p*2+1];
        }

        void prop(ll p, ll L, ll R){
            if(lazy[p] == -1) return;

            ll mid = (L+R)/2;
            st[p] = lazy[p];

            if(L!=R){
                lazy[p*2] = lazy[p];
                lazy[p*2+1] = lazy[p];
            }
            

            lazy[p] = -1;
        }

        SegmentTree(ll n, vector<ll> &t) : st(4*n), lazy(4*n, -1){
            arr = t;
            build(1, 0, n-1);
        }

        void update (ll p, ll L, ll R, ll i, ll j, ll val){

            prop(p, L, R);
            if(i > j) return;

            if(L >= i && j >= R){
                lazy[p] = val;
                prop(p, L, R);
                return;
            }

            ll mid = (L+R)/2;

            update(p*2, L, mid, i, min(j, R), val);
            update(p*2+1, mid+1, R, max(i, L), R, val);
        }

        ll RSQ (ll p, ll L, ll R, ll i, ll j){
            prop(p, L, R);
            if(i > j) return;

            if(L >= i && j >= R){
                return st[p];
            }

            ll mid = (L+R)/2;

            ll left = RSQ(p*2, L, mid, i, min(j, R));
            ll right = RSQ(p*2+1, mid+1, R, max(i, L), j);
        }
};

