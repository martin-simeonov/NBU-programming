// f86388_9a.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

const int MAX_VALUE = 10000;

void print(unsigned s, int *d, int n) {
    for (int i = 0; i < n; ++i) {
        if (i != s) {
            if (d[i] == MAX_VALUE) {
                cout << -1;
            } else {
                cout << d[i];
            }
        } else {
            cout << 0;
        }
        cout << " ";
    }
    cout << endl;
}

void dijkstra(unsigned s, unsigned **A, unsigned n) {
    int *d = new int[n];
    int *pred = new int[n];
    int *T = new int[n];

    for (int i = 0; i < n; ++i)
    if (A[s][i] == 0) {
        d[i] = MAX_VALUE;
        pred[i] = -1;
    } else {
        d[i] = A[s][i];
        pred[i] = s;
    }

    for (int i = 0; i < n; ++i) T[i] = 1;
    T[s] = 0;
    pred[s] = -1;

    while (1) {
        int j = -1;
        int di = MAX_VALUE;

        for (int i = 0; i < n; ++i) {
            if (T[i] && d[i] < di) {
                di = d[i];
                j = i;
            }
        }
        if (j == -1) break;
        T[j] = 0;

        for (int i = 0; i < n; ++i) {
            if (T[i] && A[j][i] != 0) {
                if (d[i] > d[j] + A[j][i]) {
                  d[i] = d[j] + A[j][i];
                  pred[i] = j;
                }
            }
        }
    }

    print(s, d, n);

    delete [] d;
    delete [] pred;
    delete [] T;
}

int main() {
    unsigned num, n;
    unsigned v1, v2, w;
    set<unsigned> vertex;
    vector<unsigned> edges;

    bool firstLine = true;

    while(cin >> num) {
        if (!firstLine) cout << endl;
        firstLine = false;

        for (int i = 0; i < num; ++i) {
            cin >> v1 >> v2 >> w;
            edges.push_back(v1 - 1);
            edges.push_back(v2 - 1);
            edges.push_back(w);
            vertex.insert(v1);
            vertex.insert(v2);
        }

        n = *vertex.rbegin();

        // initialize matrix
        unsigned **A = new unsigned*[n];
        for (int i = 0; i < n; ++i) {
            A[i] = new unsigned [n];
            for (int j = 0; j < n; ++j)
                A[i][j] = 0;
        }

        for (int i = 0; i < edges.size(); i += 3)
            A[edges[i]][edges[i + 1]] = edges[i + 2];

        for (set<unsigned>::iterator it = vertex.begin(); it != vertex.end(); it++)
            dijkstra((*it) - 1, A, n);

        vertex.clear();
        edges.clear();

        // free matrix resources
        for (int i = 0; i < n; ++i)
            delete [] A[i];
        delete [] A;
    }
}
