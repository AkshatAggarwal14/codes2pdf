vector<vector<int>> scc = Kosaraju(g, n);
DSU dsu(n);
for (auto &x : scc) {
    for (auto &y : x) {
        dsu.Merge(y, x[0]);
    }
}
vector<vector<int>> compressedGraph(n + 1);
for (auto &x : edges) {
    int u = dsu.Find(x[0]), v = dsu.Find(x[1]);
    if (u == v) continue;
    compressedGraph[u].push_back(v);
}