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

    vector<int> seq1 = readToVector();
    vector<int> seq2 = readToVector();
    return "TODO: Problem 2";
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