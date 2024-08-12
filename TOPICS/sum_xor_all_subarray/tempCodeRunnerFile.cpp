    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll sum = 0;
    for (int i = 0; i < 4; i++) {
        ll x = (1 << i);
        ll odd = 0;
        for (int j = 1; j <= n; j++) {
            if (A[j] & x) odd = j - odd;
            sum += (x * odd);
        }
        cout << "\n";
    }

    cout << sum << "\n";