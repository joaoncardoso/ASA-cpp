#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

//========================================= Declarations ===========================================

// Solves problem 1
void problem1();

// Reads a line of integers from the terminal to the vector given
void cinToVector(vector<int> &seq);

// Solves problem 2
void problem2();

// Reads a line of integers from the terminal to the vector and set given
void cinToVectorSet(vector<int> &seq, unordered_set<int> &seqset);

// Reads a line of integers from the terminal to the vector given, only if they belong to the set given
void cinToVectorIfInSet(vector<int> &seq, const unordered_set<int> &seqset);

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
        lis[i] = quant[i] = 1;
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                if (lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                    quant[i] = quant[j];
                }
                else
                    quant[i] += quant[j] * (lis[j] + 1 == lis[i]);
            }
        }
        if (lis[i] > res) {
            res = lis[i];
            num = quant[i];
        }
        else
            num += quant[i] * (lis[i] == res);
    }
    cout << res << " " << num << endl;
}

//=========================================== Problem 2 ============================================

void problem2() {

    vector<int> seq1; vector<int> seq2;
    unordered_set<int> seq1set;
    cinToVectorSet(seq1, seq1set);
    cinToVectorIfInSet(seq2, seq1set);
    int size1 = seq1.size(), size2 = seq2.size(), res = 0;

    int lcis[size2] = {0}; // lcis = longest common increasing subsequence

    for (int i = 0; i < size1; i++) {
        int curr = 0;
        for (int j = 0; j < size2; j++) {
            if (seq2[j] < seq1[i])
                curr = max(curr, lcis[j]);
            else if (seq2[j] == seq1[i]) {
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

void cinToVectorSet(vector<int> &seq, unordered_set<int> &seqset) {

    int num;
    string line;
    getline(cin, line);
    istringstream ss(line);

    while (ss >> num) {
        seq.push_back(move(num));
        seqset.insert(move(num));
    }
}

void cinToVectorIfInSet(vector<int> &seq, const unordered_set<int> &seqset) {

    int num;
    string line;
    getline(cin, line);
    istringstream ss(line);

    while (ss >> num) {
        if (seqset.count(move(num)))
            seq.push_back(move(num));
    }
}