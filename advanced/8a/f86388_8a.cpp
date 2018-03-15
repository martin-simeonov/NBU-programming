// f86388_8a.cpp

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAXN 1000
#define FN 86388

unsigned n;

char used[MAXN];

void BFS(unsigned i, bool **A) {
    unsigned k, j, p, queue[MAXN], currentVert, levelVertex, queueEnd;
    for (k = 0; k < n; k++) queue[k] = 0;
    for (k = 0; k < n; k++) used[k] = 0;
    queue[0] = i;  used[i] = 1;
    currentVert = 0; levelVertex = 1; queueEnd = 1;
    while (currentVert < queueEnd) {
        for (p = currentVert; p < levelVertex; p++) {
            cout << queue[p] + 1 << " ";
            currentVert++;

            for (j = 0; j < n; j++) {
                if (A[queue[p]][j] && !used[j]) {
                    queue[queueEnd++] = j;
                    used[j] = 1;
                }
            }
        }
        levelVertex = queueEnd;
    }
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
    BFS(FN % n, A);
    cout << endl;

    for (int i = 0; i < n; ++i) {
        delete [] A[i];
    }
    delete [] A;
}
