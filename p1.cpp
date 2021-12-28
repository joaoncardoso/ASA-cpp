#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
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
    vector<int> lss (1, 1); // lss = Longest Subsequence Size
    vector<int> freq (1, 1);
    int longest = 1, num = 0, size = seq.size();
    for (int i = 1; i < size; i++) {
        lss.push_back(0);
        freq.push_back(0);
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                if (lss[j] + 1 > lss[i]) {
                    lss[i] = lss[j] + 1;
                    freq[i] = freq[j];
                }
                else if (lss[j] + 1 == lss[i])
                    freq[i] += freq[j];
            }
            else if (lss[i] < 1)
                lss[i] = freq[i] = 1;
        }
        longest = max(lss[i], longest);
    }
    for (int i = 0; i < size; i++) {
        if (lss[i] == longest)
            num += freq[i];
    }
    return to_string(longest) + ' ' + to_string(num) + '\n';
}

string problem2() {
    // não funciona para {1 2 6 3 7} e {1 2 4 7}, a LCSS até ao 3 da seq1 é 3,
    // mas até ao 7 não é 3+1 porque esse 3 englobava a subsequência {1 2 3}
    // no segundo que não poderia ter o 7 a seguir

    vector<int> seq1 = readToVector();
    vector<int> seq2 = readToVector();
    int longest = 0, pos_seq2, size1 = seq1.size(), size2 = seq2.size();
    vector<int> lcss (size1, 0);    // lcss = Longest Common Subsequence Size
    bool matched;
    for (int i = 0; i < size1; i++) {
        matched = false;
        for (int j = size2 - 1; j >= 0; j--) {
            if (seq1[i] == seq2[j]){
                matched = true;
                pos_seq2 = j;
                break;
            }
        }
        if (!matched) continue;
        for (int k = min(i-1, pos_seq2); k >= 0; k--) {
            if (seq1[k] < seq1[i]) {
                lcss[i] = max(lcss[k] + 1, lcss[i]);
            }
        }
        lcss[i] = max(lcss[i], 1);
        cout << lcss[i];    // debugging
        longest = max(lcss[i], longest);
    }
    cout << endl;   // debugging
    return to_string(longest) + '\n';
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