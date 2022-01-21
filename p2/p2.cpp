#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//========================================= Declarations ===========================================

// Colors availabe for each vertex (white by default)
enum colors {
    white, red, blue, purple, black
};

// Each vertex holds its color and its parents' vertex numbers
struct vertex {
    unsigned int p1 = 0;
    unsigned int p2 = 0;
    colors color = white;
    bool clear = false;
};

// Reads a line of 2 integers to the arguments given from the standard input
int cinToIntegers(int &a, int &b);

// Performs a Distance First Search recursively and colors each vertex
void dfs(int v, colors c, vertex vertices[]);

// TODO
bool has_cycle(int v, unordered_set<int> path, vertex vertices[]);

//============================================= Main ===============================================

int main() {

    int v1, v2, num_vertices, num_edges, p, c;

    cinToIntegers(v1, v2);
    cinToIntegers(num_vertices, num_edges);

    vertex* vertices = new vertex[num_vertices + 1];
    string res;

    // Input reading
    for (int i = 0; i < num_edges; i++) {
        if (cinToIntegers(p, c) != 0) {
            printf("0\n");
            return -1;
        }
        if (vertices[c].p1 == 0)
            vertices[c].p1 = p;
        else if (vertices[c].p2 == 0)
            vertices[c].p2 = p;
        else {  // Crowded parents exception
            printf("0\n");
            return -1;
        }
    }

    // Tree cycles exception
    for (int i = 1; i <= num_vertices; i++) {
        unordered_set<int> path;
        if (has_cycle(i, path, vertices)) {
            printf("0\n");
            return -1;
        }
    }

    // 2 DFS, one for each vertex
    dfs(v1, red, vertices);
    dfs(v2, blue, vertices);

    // Results processing
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

int cinToIntegers(int &a, int &b) {

    if (scanf(" %d", &a) && scanf(" %d", &b))
        return 0;
    return -1;
}

void dfs(int v, colors c, vertex vertices[]) {

    if (vertices[v].color == red && c == blue)
        c = purple;
    vertices[v].color = c;
    int p = vertices[v].p1;
    for (int i = 0; i < 2; i++, p = vertices[v].p2) {
        if (p != 0) {
            if (vertices[p].color == white || (vertices[p].color == red && c == blue))
                dfs(p, c, vertices);
            else if (c == purple || c == black)
                dfs(p, black, vertices);
        }
    }
}

bool has_cycle(int v, unordered_set<int> path, vertex vertices[]) {

    if (vertices[v].clear == true)
        return false;
    if (path.count(v) > 0)
        return true;
    else {
        path.insert(v);
        vertices[v].clear = true;
    }
    int p = vertices[v].p1;
    for (int i = 0; i < 2; i++, p = vertices[v].p2) {
        if (p != 0)
            return has_cycle(p, path, vertices);
    }
    return false;
}