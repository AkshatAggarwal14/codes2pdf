int n, q;
vector<ll> a, lazy;
vector<matrix> t;

void build(int in = 1, int s = 0, int e = n - 1) {
    if (s == e) {
        t[in] = fib(a[s]);
    } else {
        int mid = (s + e) >> 1;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = t[2 * in] + t[2 * in + 1];
    }
}

void push(int in) {
    if (lazy[in] != 0) {
        lazy[2 * in] += lazy[in];
        lazy[2 * in + 1] += lazy[in];

        t[2 * in] = t[2 * in] * fib(lazy[in]);
        t[2 * in + 1] = t[2 * in + 1] * fib(lazy[in]);

        lazy[in] = 0;
    }
}

void update(int in, int s, int e, int qs, int qe, int val, matrix& toAdd) {
    if (qs > qe) {
        return;
    }

    if (s == qs && e == qe) {
        t[in] = t[in] * toAdd;
        lazy[in] += val;
    } else {
        push(in);
        int mid = (s + e) >> 1;
        update(2 * in, s, mid, qs, min(mid, qe), val, toAdd);
        update(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe, val, toAdd);

        t[in] = t[2 * in] + t[2 * in + 1];
    }
}

int query(int in, int s, int e, int qs, int qe) {
    if (qs > qe) {
        return 0;
    }

    if (s == qs && e == qe) {
        return t[in].mat[0][1];
    }

    push(in);

    int mid = (s + e) >> 1;

    return (query(2 * in, s, mid, qs, min(mid, qe)) +
            query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe)) %
           MOD;
}