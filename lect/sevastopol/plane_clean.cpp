#include <boost/config.hpp>
#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/boyer_myrvold_planar_test.hpp>

using namespace boost;
using namespace std;

int main() {

        typedef adjacency_list <vecS, vecS, undirectedS> graph_t;

        int n, m;
        cin >> n >> m;
        graph_t g(n);

        for (int i = 0; i < m; ++i) {
                int a, b;
                cin >> a >> b;
                add_edge(a, b, g);
        }

        typedef vector <graph_traits<graph_t>::edge_descriptor> vec_t;
        vector <vec_t> embedding(num_vertices(g));

        if (boyer_myrvold_planarity_test(boyer_myrvold_params::graph = g,
                                                                         boyer_myrvold_params::embedding = &embedding[0])
                                                                        )       {
                cout << "YES" << endl;
        } else {
                cout << "NO" << endl;
        }

        return 0;
}
