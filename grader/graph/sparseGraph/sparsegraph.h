#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <vector>
#include <set>
using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        // Your code here
        SparseGraph(3);
    }

    SparseGraph(int n_in) {
        // Your code here
        v = n_in;
        edge.resize(n_in);
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        SparseGraph(G.v);
    }

    void AddEdge(int a, int b) {
        // Your code here
        edge[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        edge[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return edge[a].find(b) != edge[a].end();
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph res(v);
        for(int i=0;i<edge.size();i++) {
            for(const auto &x: edge[i]) {
                res.AddEdge(x,i);
            }
        }
        return res;
    }

protected:
    // Your code here
    int v;
    vector<set<int>> edge;
};
#endif // __SPARSE_GRAPH_H__

