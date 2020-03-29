// https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        for (int t = 0; t < n; ++t) {
            if (d[i][t] < INF && d[t][t] < 0 && d[t][j] < INF)
                d[i][j] = - INF; 
        }
    }
}


/* OR use Spfa , De'spo pape , Belman Fold Form every source */
