#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


// DECLARATIONS (to be added to p1.h afterwards)
vector<int> readToVector();
// Problem 1
string problem1();
// Problem 2
string problem2();


int main() {

    string command;
    getline(cin, command);
    if (command.compare("1") == 0)
        cout << problem1();
    else
        cout << problem2();
}

string problem1() {
    vector<int> seq = readToVector();
    vector<int> lcs (1, 1);
    vector<int> freq (1, 1);
    int max = 1, num = 0, size = seq.size();
    for (int i = 1; i < size; i++) {
        lcs.push_back(0);
        freq.push_back(0);
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                if (lcs[j] + 1 > lcs[i]) {
                    lcs[i] = lcs[j] + 1;
                    freq[i] = freq[j];
                }
                else if (lcs[j] + 1 == lcs[i])
                    freq[i] += freq[j];
            }
            else if (lcs[i] < 1)
                lcs[i] = freq[i] = 1;
        }
        if (lcs[i] > max)
            max = lcs[i];
    }
    for (int i = 0; i < size; i++) {
        if (lcs[i] == max)
            num += freq[i];
    }
    return to_string(max) + ' ' + to_string(num) + '\n';
}

string problem2() {
    // não funciona - ao preencher a tabela para 1 2 6 3 7 e 1 2 4 7 a maior subsequência comum até ao 3 do primeiro vetor é 3, mas até ao 7 não é 3+1 porque esse 3 englobava a subsequência 1 2 3 no segundo que não poderia ter o 7 a seguir

    vector<int> seq1 = readToVector();
    vector<int> seq2 = readToVector();
    int maxn = 0, pos_seq2, size1 = seq1.size(), size2 = seq2.size();
    vector<int> lcs (size1, 0);
    bool unmatched;
    for (int i = 0; i < size1; i++) {
        unmatched = true;
        for (int j = size2 - 1; j >= 0; j--) {
            if (seq1[i] == seq2[j]){
                unmatched = false;
                pos_seq2 = j;
                break;
            }
        }
        if (unmatched) continue;
        for (int k = 0; k <= pos_seq2; k++) {
            if (seq1[k] < seq1[i]) {
                lcs[i] = max(lcs[k] + 1, lcs[i]);
            }
        }
        lcs[i] = max(lcs[i], 1);
    }
    for (int i = 0; i < size1; i++) {
        cout << lcs[i];
        maxn = max(lcs[i], maxn);
    }
    return '\n' + to_string(maxn) + '\n';
}

vector<int> readToVector() {

    int number;
    string line;
    getline(cin, line);
    istringstream ss(line);
    vector<int> sequence;

    while (ss >> number)
        sequence.push_back(number);

    return sequence;
}