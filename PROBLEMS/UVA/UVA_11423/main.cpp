#include <bits/stdc++.h>
#define LSOne(n) ((n) & (-n))
using namespace std;

int A[(1 << 24) + 5]; // A[i] shows the last time the memory with id i is called
int cacheSize[35];
int miss[35];

// RUPQ
struct Fenwick {
    vector<int> __ft; // ft[j] is the shifts of rank j
    int __size;

    Fenwick(int size) : __ft(2*size) {
        __size = 2*size;
    }

    // point query
    int RSQ(int i) {
        int sum = 0;
        while (i > 0) {
            sum += __ft[i];
            i -= LSOne(i);
        }
        return sum;
    }

    void add(int i, int k) {
        if (i <= 0) return; // just for safety
        while(i < __size) {
            __ft[i] += k;
            i += LSOne(i);
        }
    }

    void add(int i, int j, int k) {
        if (j < i) return; // just for safety
        add(i, k); add(j+1, -k);
    }

    // print 10 first element in __ft
    void debug() {
        cout << "size = " << __size << "\n";
        cout << "first 10 element:\n";
        for (int i = 1; i <= 10; i++) {
            cout << __ft[i] << " \n"[i==10];
        }
    }
};

void logMissed(int x, int age, int N) {
    for (int i = 1; i <= N; i++) {
        if (A[x] == 0 || age > cacheSize[i]) {
            miss[i] += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Fenwick ft(1e7);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cacheSize[i];
    }

    int call = 0; // number of memory call
    while (true) {
        string cmd; cin >> cmd;
        if (cmd == "END") break;

        if (cmd == "ADDR") {
            ++call;
            int x; cin >> x;

            int rank = A[x] + ft.RSQ(A[x]);
            // cout << "rank = " << rank << "\n";
            int age = call - rank;
            // cout << "age = " << age << "\n";
            logMissed(x, age, N);
            ft.add(1, A[x]-1, 1);
            A[x] = call;
        } else if (cmd == "RANGE") {
            int b, y, n; cin >> b >> y >> n;
            for (int k = 0; k < n; k++) {
                ++call;
                int x = b + y*k;
                int rank = A[x] + ft.RSQ(A[x]);
                int age = call - rank;
                logMissed(x, age, N);
                ft.add(1, A[x]-1, 1);
                A[x] = call;
            }
        } else {
            for (int i = 1; i <= N; i++) {
                cout << miss[i] << " \n"[i==N];
                miss[i] = 0;
            }
        }
    }

    // ft.debug();    
    return 0;
}

/*
1
4
RANGE 1 1 4
STAT
ADDR 2
STAT
ADDR 1
STAT
END


1
1
RANGE 1 1 1
STAT
END

1
2
ADDR 3
ADDR 3
ADDR 3
ADDR 3
ADDR 3
ADDR 3
ADDR 4
ADDR 4
ADDR 3
STAT
END

1
3
ADDR 1
ADDR 2
ADDR 3
ADDR 1
STAT
ADDR 1
ADDR 2
ADDR 3
ADDR 4
ADDR 1
ADDR 2
ADDR 3
ADDR 4
STAT
END


1
2
RANGE 1 1 10000
STAT
ADDR 1
STAT
END
*/