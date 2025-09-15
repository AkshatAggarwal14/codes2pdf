template <class T>
vector<int> coordinateCompress(const vector<T> &a) {
    int n = int(a.size());

    vector<pair<T, int>> v(n);
    for (int i = 0; i < n; ++i) v[i] = {a[i], i};
    sort(v.begin(), v.end());
    vector<int> res(n);
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || v[i].first != v[i - 1].first) {
            ++curr;
        }
        res[v[i].second] = curr;
    }
    return res;
}