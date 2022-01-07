#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//========================================= Declarations ===========================================

// Solves problem 1
void problem1();

// Reads a line of integers from the terminal to the vector given
void cinToVector(vector<int> &seq);

// Solves problem 2
void problem2();

// Reads a line of integers from the terminal to the vector and map given
void cinToVectorMap(vector<int> &seq, unordered_map<int, int> &seqmap);

// Reads a line of integers from the terminal to the vector given, only if they belong to the map given
void cinToVectorIfInMap(vector<int> &seq, const unordered_map<int, int> &seqmap);

//============================================= Main ===============================================

int main() {

    string comm;
    getline(cin, comm);
    if (comm.compare("1") == 0)
        problem1();
    else
        problem2();
}

//=========================================== Problem 1 ============================================

void problem1() {
    vector<int> seq;
    cinToVector(seq);
    int res = 1, num = 0, size = seq.size();
    int lis[size];     // lis = longest increasing subsequence
    int quant[size];   // quant = quantity
    for (int i = 0; i < size; i++) {
        int lis_val = 1, quant_val = 1;
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                if (lis[j] + 1 > lis_val) {
                    lis_val = lis[j] + 1;
                    quant_val = quant[j];
                }
                else
                    quant_val += quant[j] * (lis[j] + 1 == lis_val);
            }
        }
        if (lis_val > res) {
            res = lis_val;
            num = quant_val;
        }
        else
            num += quant_val * (lis_val == res);
        lis[i] = move(lis_val);
        quant[i] = move(quant_val);
    }
    cout << res << " " << num << endl;
}

//=========================================== Problem 2 ============================================

void problem2() {

    vector<int> seq1; vector<int> seq2;
    unordered_map<int, int> seq1map;
    cinToVectorMap(seq1, seq1map);
    cinToVectorIfInMap(seq2, seq1map);
    int size1 = seq1.size(), size2 = seq2.size(), res = 0;

    int lcis[size2] = {0}; // lcis = longest common increasing subsequence

    for (int i = 0; i < size1; i++) {
        int curr = 0;
        for (int j = 0; j < size2; j++) {
            if (seq1[i] > seq2[j])
                curr = max(curr, lcis[j]);
            else if (seq1[i] == seq2[j]) {
                lcis[j] = max(curr + 1, lcis[j]);
                res = max(lcis[j], res);
            }
        }
    }
    cout << res << endl;
}

//====================================== Auxiliary Functions =======================================

void cinToVector(vector<int> &seq) {

    int num;
    string line;
    getline(cin, line);
    istringstream ss(line);

    while (ss >> num)
        seq.push_back(move(num));
}

void cinToVectorMap(vector<int> &seq, unordered_map<int, int> &seqmap) {

    int num;
    string line;
    getline(cin, line);
    istringstream ss(line);

    while (ss >> num) {
        seq.push_back(move(num));
        seqmap.insert(make_pair(move(num), NULL));
    }
}

void cinToVectorIfInMap(vector<int> &seq, const unordered_map<int, int> &seqmap) {

    int num;
    string line;
    getline(cin, line);
    istringstream ss(line);

    while (ss >> num) {
        if (seqmap.count(num))
            seq.push_back(move(num));
    }
}