ll x = 1e14;
    for (ll step = x; step > 0; step /= 2) {
        while (x - step >= mx && f(x-step)) x -= step;
    }

    cout << x << "\n";