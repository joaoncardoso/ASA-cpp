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
struct cell {
    int value;
    bool matched;
};


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
                else {
                    freq[i] += freq[j] * (lss[j] + 1 == lss[i]);
                }
                // else if (lss[j] + 1 == lss[i])
                //     freq[i] += freq[j];
            }
            else if (lss[i] < 1)
                lss[i] = freq[i] = 1;
        }
        longest = max(lss[i], longest);
    }
    for (int i = 0; i < size; i++) {
        num += freq[i] * (lss[i] == longest);
        // if (lss[i] == longest)
        //     num += freq[i];
    }
    return to_string(longest) + ' ' + to_string(num) + '\n';
}


//===========================================================================================================
// MOOSHAK 1050 JOTA

bool has(vector<int> v, int k) {
    int s = (int)v.size();
    for (int i = 0; i < s; i++) {
        if (v[i] == k) return true;
    }
    return false;
}

string problem2() {
    vector<int> seq1 = readToVector();
    vector<int> seq2 = readToVector();
    int size1 = seq1.size(), size2 = seq2.size();
    vector<vector<int>> lcss = {}; // lcss = Longest Common Subsequence Size
    vector<vector<int>> pins = {};

    vector<int> common1; // removing uncommon elements between the two vectors
    vector<int> common2;

    for (int i = 0; i < (int)seq1.size(); i++) {
        if (has(seq2, seq1[i])) {
            common1.push_back(seq1[i]);
        }
    }
    for (int i = 0; i < (int)seq2.size(); i++) {
        if (has(common1, seq2[i])) {
            common2.push_back(seq2[i]);
        }
    }
    size1 = (long)common1.size();
    size2 = (long)common2.size();

    for (int i = 0; i < size1; i++) {  // DBG
        cout << common1[i] << " ";     // DBG
    }                                  // DBG
    cout << endl;                      // DBG
    for (int i = 0; i < size2; i++) {  // DBG
        cout << common2[i] << " ";     // DBG
    }                                  // DBG
    cout << endl;                      // DBG  

    for (int i = 0; i <= size1; i++) {
        vector<int> lcssline = {};
        vector<int> pinsline = {};
        for (int j = 0; j <= size2; j++) {
            if (i * j == 0)
                lcssline.push_back(0);
            else if (common1[i-1] == common2[j-1]) {  // match!
                pinsline.push_back(j);
                lcssline.push_back(0);
                for (int k = i-1; k > 0; k--) {
                    for (int l = pins[k].size()-1; l >= 0; l--) {
                        if (common2[pins[k][l]-1] < common2[j-1] && pins[k][l] < j) {
                            lcssline[j] = lcss[k][pins[k][l]] + 1;
                            goto jump;
                        }
                    }
                }
                jump: lcssline[j] = max(max(lcssline[j], 1), max(lcss[i-1][j], lcssline[j-1]));
            }
            else
                lcssline.push_back(max(lcss[i-1][j], lcssline[j-1]));
            cout << to_string(lcssline[j]) + ' ';       // DBG
        }
        cout << "  (pins: ";                            // DBG
        for (int k = 0; k < (int)pinsline.size(); k++)  // DBG
            cout << to_string(pinsline[k]) + ',';       // DBG
        cout << ")\n";                                  // DBG
        lcss.push_back(lcssline);
        pins.push_back(pinsline);
   }
   return to_string(lcss[size1][size2]) + '\n';
}


//===========================================================================================================
// MOOSHAK 1200 JOTA

// string problem2() {
//     vector<int> seq1 = readToVector();
//     vector<int> seq2 = readToVector();
//     int size1 = seq1.size(), size2 = seq2.size();
//     vector<vector<cell>> lcss = {}; // lcss = Longest Common Subsequence Size

//     for (int i = 0; i <= size1; i++) {
//         vector<cell> line = {};
//         for (int j = 0; j <= size2; j++) {
//             if (i * j == 0)
//                 line.push_back({0, false});
//             else if (seq1[i-1] == seq2[j-1]) {  // match!
//                 line.push_back({0, true});
//                 for (int k = j-2; k >= 0; k--) {
//                     if (seq2[k] < seq2[j-1] && lcss[i-1][k+1].matched == true) {
//                         line[j].value = lcss[i-1][k+1].value + 1;
//                         break;
//                     }
//                 }
//                 line[j].value = max(max(line[j].value, 1), max(lcss[i-1][j].value, line[j-1].value));
//             }
//             else {
//                 bool matched = (lcss[i-1][j].matched == true && lcss[i-1][j].value >= line[j-1].value) ? true : false;
//                 line.push_back({max(lcss[i-1][j].value, line[j-1].value), matched});
//             }
//             cout << to_string(line[j].value) + ' ';   // DBG
//         }
//         lcss.push_back(line);
//         cout << endl;                                 // DBG
//    }
//    return to_string(lcss[size1][size2].value) + '\n';
// }



//===========================================================================================================
// JOÃO

// string problem2() {
//     vector<int> seq1 = readToVector();
//     vector<int> seq2 = readToVector();
//     const long size1 = seq1.size();//, size2 = seq2.size();
//     auto lcss = new int [size1 + 1][10001];
//     // int lcss[seq1.size()+1][seq2.size()+1] = {};  // lcss = Longest Common Subsequence Size

//     for (int i = 0; i <= (int)seq1.size(); i++) {
//         for (int j = 0; j <= (int)seq2.size(); j++) {
//             bool has(vector<int> v, int k) {
//     int s = (int)v.size();
//     for (int i = 0; i < s; i++) {
//         if (v[i] == k) return true;
//     }
//     return false;
// }if (i * j == 0)
//                 lcss[i][j] = 0;
//             else if (seq1[i-1] == seq2[j-1]) {  // match!
//                 if (seq1[pin] < seq2[j-1]) {
//                     lcss[i][j] = lcss[i-1][j-1] + 1;
//                     pin = j-1;
//                 } 
//                 else if (seq1[pin] > seq2[j-1]) {
//                     pin = j-1;
//                 }
//                 lcss[i][j] = max(max(lcss[i][j], 1), max(lcss[i-1][j], lcss[i][j-1]));
//             }
//             else
//                 lcss[i][j] = max(lcss[i-1][j], lcss[i][j-1]);
//         }
//     }
//     return to_string(lcss[seq1.size()][seq2.size()]) + '\n';
// }

// JOÃO NÃO FUNCIONAL
string problem22() {
    vector<int> seq1 = readToVector();
    vector<int> seq2 = readToVector();
    long size1 = seq1.size(), size2 = seq2.size();
    // int lcss[size1 + 1][size2+1] = {};  // lcss = Longest Common Subsequence Size
    auto lcss = new int [size1 + 1][10001];
    int pin = -1, prevpin = -1;
    vector<int> common1;
    vector<int> common2;
    vector<int> temp_seq;
    for (int i = 0; i < (int)seq1.size(); i++) {
        if (has(seq2, seq1[i])) {
            common1.push_back(seq1[i]);
        }
    }
    for (int i = 0; i < (int)seq2.size(); i++) {
        if (has(common1, seq2[i])) {
            common2.push_back(seq2[i]);
        }
    }
    size1 = (long)common1.size();
    size2 = (long)common2.size();
    for (int i = 0; i < size1; i++) {
        cout << common1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size2; i++) {
        cout << common2[i] << " ";
    }
    cout << endl;

    
    for (int i = 0; i <= size1; i++) {
        for (int j = 0; j <= size2; j++) {
            if (i * j == 0)
                lcss[i][j] = 0;
            else if (common1[i-1] == common2[j-1]) {  // match!
                cout << " match " << common2[j-1] << endl;
                if (common2[pin] < common2[j-1]) {
                    lcss[i][j] = lcss[i-1][j-1] + 1;
                    if (j-1 > pin || (temp_seq.size() == 1)) {
                        prevpin = pin;
                        pin = j-1;
                    }
                    cout << " pin " << common2[pin] << endl;
                }
                else if (common2[pin] > common2[j-1] && common2[j-1] >= common2[prevpin]) {
                    cout << j-1 << " " << pin <<endl;
                    if (j-1 > pin) {
                        prevpin = pin;
                        pin = j-1;
                    }
                    cout << " pin2 " <<common2[pin] << endl;
                }
                lcss[i][j] = max(max(lcss[i][j], 1), max(lcss[i-1][j], lcss[i][j-1]));
            }
            else
                lcss[i][j] = max(lcss[i-1][j], lcss[i][j-1]);
        }
    }
    for (int i = 0; i < size1 + 1; i++) {
      for (int j = 0; j < size2 + 1; j++) {
        cout << lcss[i][j] << " ";
      }

      // Newline for new row
      cout << endl;
    }
    return to_string(lcss[size1][size2]) + '\n';
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