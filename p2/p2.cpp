#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const int MAX_PARENTS = 2;

//========================================= Declarations ===========================================

// Colors availabe for each vertex (white by default)
enum colors {
    white, red, blue, purple, black
};

// Each vertex holds its color and its parents' vertex numbers
struct vertex {
    int parents[MAX_PARENTS] = {-1, -1};
    colors color = white;
};

// Reads a line of 2 integers to the arguments given from the standard input
void cinToIntegers(int &a, int &b);

// Performs a Distance First Search recursively and colors each vertex
void dfs(int v, colors c, vertex vertices[]);

//============================================= Main ===============================================

int main() {

    int v1, v2, num_vertices, num_edges, p, c;
    int busy = 0;

    cinToIntegers(v1, v2);
    cinToIntegers(num_vertices, num_edges);

    //vertex vertices[num_vertices + 1];
    vertex* vertices = new vertex[num_vertices + 1];
    vector<int> lca;    // lca = lowest common ancestors
    string res;

    for (int i = 0; i < num_edges; i++) {
        cinToIntegers(p, c);
        for (int i = 0, busy = 0; i < MAX_PARENTS; ++i) {
            if (vertices[c].parents[i] == -1) {
                vertices[c].parents[i] = p;
                break;
            } else busy +=1;
        }
        if (busy == 2) return -1;
    }

    // 2 DFS, uma por cada um dos vértices
    dfs(v1, red, vertices);
    dfs(v2, blue, vertices);

    for (int i = 1; i <= num_vertices; i++) {
        if (vertices[i].color == purple)
            lca.push_back(i);
    }

    // No results exception
    if (lca.empty())
        res = "-";
    else {  // Results available
        for (int i = 0; i < (int)lca.size(); i++)
            res += to_string(lca[i]) + " ";
    }
    cout << res << endl;
    return 0;
}

//====================================== Auxiliary Functions =======================================

void cinToIntegers(int &a, int &b) {

    string line;
    getline(cin, line);
    istringstream ss(line);

    ss >> a;
    ss >> b;
}

void dfs(int v, colors c, vertex vertices[]) {

    if (vertices[v].color == red && c == blue)
        c = purple;
    vertices[v].color = c;
    int i, p;
    for (i = 0; i < MAX_PARENTS; i++) {
        p = vertices[v].parents[i];
        if (p != -1) {
            if (vertices[p].color == white || (vertices[p].color == red && c == blue))
                dfs(p, c, vertices);
            else if (c == purple || c == black)
                dfs(p, black, vertices);
        }
    }
}