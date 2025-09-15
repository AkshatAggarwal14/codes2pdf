auto toposort = [&]() {
    vector<bool> visited(n + 1, false);
    stack<ll> st;

    function<void(ll)> dfs = [&](ll node) {
        visited[node] = true;

        for (auto &child : g[node]) {
            if (!visited[child]) {
                dfs(child);
            }
        }

        st.push(node);
    };

    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    vector<ll> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
};