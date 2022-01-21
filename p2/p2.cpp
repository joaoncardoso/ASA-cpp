#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//========================================= Declarations ===========================================

// Colors availabe for each vertex (white by default)
enum colors {
    white, red, blue, purple, black
};

// Each vertex holds its color and its parents' vertex numbers
struct vertex {
    int p1 = -1;
    int p2 = -1;
    colors color = white;
};

// Reads a line of 2 integers to the arguments given from the standard input
void cinToIntegers(int &a, int &b);

// Performs a Distance First Search recursively and colors each vertex
void dfs(int v, colors c, vertex vertices[]);

//============================================= Main ===============================================

int main() {

    int v1, v2, num_vertices, num_edges, p, c;

    cinToIntegers(v1, v2);
    cinToIntegers(num_vertices, num_edges);

    vertex* vertices = new vertex[num_vertices + 1];
    string res;

    for (int i = 0; i < num_edges; i++) {
        cinToIntegers(p, c);
        if (vertices[c].p1 == -1)
            vertices[c].p1 = p;
        else if (vertices[c].p2 == -1)
            vertices[c].p2 = p;
        else {  // Crowded parents exception
            cout << 0 << endl;
            return -1;
        }
    }

    // 2 DFS, one for each vertex
    dfs(v1, red, vertices);
    dfs(v2, blue, vertices);

    for (int i = 1; i <= num_vertices; i++) {
        if (vertices[i].color == purple)
            res += (to_string(i) + " ");
    }

    // No results exception
    if (res.empty())
        res = "-";
   
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
    int p = vertices[v].p1;
    for (int i = 0; i < 2; i++, p = vertices[v].p2) {
        if (p != -1) {
            if (vertices[p].color == white || (vertices[p].color == red && c == blue))
                dfs(p, c, vertices);
            else if (c == purple || c == black)
                dfs(p, black, vertices);
        }
    }
}