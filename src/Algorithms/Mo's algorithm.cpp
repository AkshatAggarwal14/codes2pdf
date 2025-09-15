// TODO: Find optimal block_size for compiler optimization
const int block_size = 450;  // sqrt(N)
// TODO: Define constants needed for global variables (arrays etc. - The DS)
const int N = 200005;
const int MX = 1E6 + 5;

// TODO: initialize data structure, along with answer variable - can define get_answer() function also
ll a[N], cnt[MX], sum[N];
ll ans;

struct Query {
    int l, r, idx;
    Query() = default;
    Query(int L, int R, int i) : l(L), r(R), idx(i) {}
    pair<int, int> toPair() const {
        return make_pair(l / block_size, ((l / block_size) & 1) ? -r : +r);
    }
    bool operator<(const Query &other) const {
        return this->toPair() < other.toPair();
    }
};

// TODO: remove value at idx from data structure
void remove(int idx) {
    ll ocnt = cnt[a[idx]], ncnt = ocnt - 1;
    ll old_ocnt = sum[ocnt], old_ncnt = sum[ncnt];
    sum[ocnt] -= a[idx];
    --cnt[a[idx]];  // reduce count
    sum[ncnt] += a[idx];
    ll new_ocnt = sum[ocnt], new_ncnt = sum[ncnt];

    ans += ocnt * ocnt * (new_ocnt - old_ocnt);
    ans += ncnt * ncnt * (new_ncnt - old_ncnt);
}

// TODO: add value at idx from data structure
void add(int idx) {
    ll ocnt = cnt[a[idx]], ncnt = ocnt + 1;
    ll old_ocnt = sum[ocnt], old_ncnt = sum[ncnt];
    sum[ocnt] -= a[idx];
    ++cnt[a[idx]];  // increase count
    sum[ncnt] += a[idx];
    ll new_ocnt = sum[ocnt], new_ncnt = sum[ncnt];

    ans += ocnt * ocnt * (new_ocnt - old_ocnt);
    ans += ncnt * ncnt * (new_ncnt - old_ncnt);
}

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = ans;
    }
    return answers;
}