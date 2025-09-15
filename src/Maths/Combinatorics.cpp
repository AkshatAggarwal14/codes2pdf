
const ll N = 2'00'000;
const ll MOD = 1e9 + 7;  // 998244353;
ll M(ll x) { return ((x % MOD) + MOD) % MOD; }
ll add(ll x, ll y) { return (M(x) + M(y)) % MOD; }
ll mul(ll x, ll y) { return (M(x) * M(y)) % MOD; }
array<ll, N + 1> fact;
array<ll, N + 1> inv;
ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1 % m;
    ll u = modpow(x, y / 2, m);
    u = (u * u) % m;
    if (y % 2 == 1) u = (u * x) % m;
    return u;
}
// a**(p - 1) % p == 1
// a*(a**(p - 2)) % p == 1
// a**(p - 2) % p == 1 / a
ll inverse(ll a, ll m = MOD) { return modpow(a, m - 2, m); }  //Fermats little theorem
void init() {
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % MOD;
    inv[N] = inverse(fact[N]);
    for (ll i = N - 1; i >= 0; --i) inv[i] = mul(inv[i + 1], (i + 1));

    /*
    fact[0] = inv[0] = invf[0] = fact[1] = inv[1] = invf[1] = 1;
    for (ll i = 2; i <= N; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = M(-mul((MOD / i), inv[MOD % i]));
        invf[i] = mul(invf[i - 1], inv[i]);
    }
    */
}

ll C(ll a, ll b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv[b]), inv[a - b]);
}

ll P(ll a, ll b) {
    if (a < b) return 0;
    return mul(fact[a], inv[a - b]);
}
