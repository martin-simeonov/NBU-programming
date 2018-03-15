// f86388_8a.cpp

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAXN 1000
#define FN 86388

unsigned n;

char used[MAXN];

void DFS(unsigned i, bool **A) {
    unsigned k;
    used[i] = 1;
    cout << i + 1 << " ";
    for (k = 0; k < n; k++)
    if (A[i][k] && !used[k]) DFS(k, A);
}

int main() {
    unsigned a, b;
    unsigned nEdge;
    cin >> nEdge;
    vector<unsigned> edges;
    set<unsigned> vertex;
    for (int i = 0; i < nEdge; ++i) {
        cin >> a >> b;
        edges.push_back(a);
        edges.push_back(b);
        vertex.insert(a);
        vertex.insert(b);
    }
    n = *vertex.end();

    bool **A = new bool*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new bool [n];
        for (int k = 0; k < n; ++k)
            A[i][k] = 0;
    }

    for (int i = 0; i < edges.size(); i += 2) {
        A[edges[i] - 1][edges[i + 1] - 1] = 1;
        A[edges[i + 1] - 1][edges[i] - 1] = 1;
    }

    for (int j = 1; j < n; j++) used[j] = 0;
    DFS(FN % n, A);
    cout << endl;

    for (int i = 0; i < n; ++i) {
        delete [] A[i];
    }
    delete [] A;
}
