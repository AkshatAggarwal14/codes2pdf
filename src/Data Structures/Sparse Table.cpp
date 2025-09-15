template <class T, class U = function<T(const T &, const T &)>>
class Sparse_Table {
    ll N, K;
    vector<int> LOG;
    vector<vector<T>> st;
    U op;

    ll log2_floor(unsigned long long i) {
        return 63 - __builtin_clzll(i);
    }

   public:
    Sparse_Table() = default;
    Sparse_Table(const vector<T> &arr, const U &OP)
        : N(ll(arr.size())), K(log2_floor(N)), LOG(N + 1), st(N, vector<T>(K + 1)), op(OP) {
        LOG[1] = 0;
        for (ll i = 2; i <= N; i++) LOG[i] = LOG[i / 2] + 1;
        for (ll i = 0; i < N; i++)
            st[i][0] = arr[i];
        for (ll j = 1; j <= K; j++)
            for (ll i = 0; i + (1 << j) <= N; i++)
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    T query(ll L, ll R) {
        if (L > R) swap(L, R);
        ll j = LOG[R - L + 1];
        T res = op(st[L][j], st[R - (1 << j) + 1][j]);
        return res;
    }
};