#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct vector_map {
    vector<int> v;
    unordered_map<int, int> m;
};
struct cell {
    int value;
    bool matched;
};

// Declarations
vector<int> cinToVector();
vector_map cinToVectorMap();
vector_map cinToVectorMapExcept(const unordered_map<int, int> &seq);
void VectorExcept(vector<int> &seq1v, unordered_map<int, int> &seq2m);
string problem1();
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
    vector<int> seq = cinToVector();
    vector<int> lss;     // lss = longest subsequence size
    vector<int> quant;   // quant = quantity
    int longest = 1, num = 0, size = seq.size();
    for (int i = 0; i < size; i++) {
        int lss_val = 1, quant_val = 1;
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                if (lss[j] + 1 > lss_val) {
                    lss_val = lss[j] + 1;
                    quant_val = quant[j];
                }
                else
                    quant_val += quant[j] * (lss[j] + 1 == lss_val);
            }
        }
        if (lss_val > longest) {
            longest = lss_val;
            num = quant_val;
        }
        else
            num += quant_val * (lss_val == longest);
        lss.push_back(lss_val);
        quant.push_back(quant_val);
    }
    return to_string(longest) + ' ' + to_string(num) + '\n';
}



//===========================================================================================================
// MOOSHAK 1050 JOTA + edited (JOÃO)

// bool has(vector<int> v, int k) {
//     int s = (int)v.size();
//     for (int i = 0; i < s; i++) {
//         if (v[i] == k) return true;
//     }
//     return false;
// }
//
// string problem2() {
//     vector<int> seq1 = cinToVector();
//     vector<int> seq2 = cinToVector();
//     int size1 = seq1.size(), size2 = seq2.size();
//     vector<vector<int>> lcss = {}; // lcss = Longest Common Subsequence Size
//     vector<vector<int>> pins = {};
//
//     vector<int> common1; // removing uncommon elements between the two vectors
//     vector<int> common2;
//
//     for (int i = 0; i < (int)seq1.size(); i++) {
//         if (has(seq2, seq1[i])) {
//             common1.push_back(seq1[i]);
//         }
//     }
//     for (int i = 0; i < (int)seq2.size(); i++) {
//         if (has(common1, seq2[i])) {
//             common2.push_back(seq2[i]);
//         }
//     }
//     size1 = (long)common1.size();
//     size2 = (long)common2.size();
//
//     for (int i = 0; i < size1; i++) {  // DBG
//         cout << common1[i] << " ";     // DBG
//     }                                  // DBG
//     cout << endl;                      // DBG
//     for (int i = 0; i < size2; i++) {  // DBG
//         cout << common2[i] << " ";     // DBG
//     }                                  // DBG
//     cout << endl;                      // DBG  
//
//     for (int i = 0; i <= size1; i++) {
//         vector<int> lcssline = {};
//         vector<int> pinsline = {};
//         for (int j = 0; j <= size2; j++) {
//             if (i * j == 0)
//                 lcssline.push_back(0);
//             else if (common1[i-1] == common2[j-1]) {  // match!
//                 pinsline.push_back(j);
//                 lcssline.push_back(0);
//                 for (int k = i-1; k > 0; k--) {
//                     for (int l = pins[k].size()-1; l >= 0; l--) {
//                         if (common2[pins[k][l]-1] < common2[j-1] && pins[k][l] < j) {
//                             lcssline[j] = lcss[k][pins[k][l]] + 1;
//                             goto jump;
//                         }
//                     }
//                 }
//                 jump: lcssline[j] = max(max(lcssline[j], 1), max(lcss[i-1][j], lcssline[j-1]));
//             }
//             else
//                 lcssline.push_back(max(lcss[i-1][j], lcssline[j-1]));
//             cout << to_string(lcssline[j]) + ' ';       // DBG
//         }
//         cout << "  (pins: ";                            // DBG
//         for (int k = 0; k < (int)pinsline.size(); k++)  // DBG
//             cout << to_string(pinsline[k]) + ',';       // DBG
//         cout << ")\n";                                  // DBG
//         lcss.push_back(lcssline);
//         pins.push_back(pinsline);
//    }
//    return to_string(lcss[size1][size2]) + '\n';
// }


//===========================================================================================================
// MOOSHAK 1350 JOTA

string problem2() {
    vector_map seq1 = cinToVectorMap();
    vector_map seq2 = cinToVectorMapExcept(seq1.m);
    VectorExcept(seq1.v, seq2.m);
    int size1 = seq1.v.size(), size2 = seq2.v.size();
    seq1.m.clear(); seq2.m.clear();
    vector<vector<cell>> lcss = {}; // lcss = longest common subsequence size

    for (int i = 0; i < size1; i++) {       // DBG
        cout << to_string(seq1.v[i]) + ' '; // DBG
    }                                       // DBG
    cout << endl;                           // DBG
    for (int i = 0; i < size2; i++) {       // DBG
        cout << to_string(seq2.v[i]) + ' '; // DBG
    }                                       // DBG
    cout << endl;                           // DBG

    for (int i = 0; i <= size1; i++) {
        vector<cell> line = {};
        for (int j = 0; j <= size2; j++) {
            if (i * j == 0)
                line.push_back({0, false});
            else if (seq1.v[i-1] == seq2.v[j-1]) {  // match!
                line.push_back({1, true});
                for (int k = j-2; k >= 0; k--) {
                    if (seq2.v[k] < seq2.v[j-1] && lcss[i-1][k+1].matched == true) {
                        line[j].value = lcss[i-1][k+1].value + 1;
                        break;
                    }
                }
                line[j].value = max(line[j].value, max(lcss[i-1][j].value, line[j-1].value));
            }
            else {
                bool matched = (lcss[i-1][j].matched == true && lcss[i-1][j].value >= line[j-1].value) ? true : false;
                line.push_back({max(lcss[i-1][j].value, line[j-1].value), matched});
            }
            cout << to_string(line[j].value) + ' ';   // DBG
        }
        lcss.push_back(line);
        cout << endl;                                 // DBG
   }
   return to_string(lcss[size1][size2].value) + '\n';
}



//===========================================================================================================
// JOÃO
//
// string problem2() {
//     vector<int> seq1 = cinToVector();
//     vector<int> seq2 = cinToVector();
//     const long size1 = seq1.size();//, size2 = seq2.size();
//     auto lcss = new int [size1 + 1][10001];
//     // int lcss[seq1.size()+1][seq2.size()+1] = {};  // lcss = Longest Common Subsequence Size
//
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



//===========================================================================================================
// JOÃO NÃO FUNCIONAL
//
// string problem22() {
//     vector<int> seq1 = cinToVector();
//     vector<int> seq2 = cinToVector();
//     long size1 = seq1.size(), size2 = seq2.size();
//     // int lcss[size1 + 1][size2+1] = {};  // lcss = Longest Common Subsequence Size
//     auto lcss = new int [size1 + 1][10001];
//     int pin = -1, prevpin = -1;
//     vector<int> common1;
//     vector<int> common2;
//     vector<int> temp_seq;
//     for (int i = 0; i < (int)seq1.size(); i++) {
//         if (has(seq2, seq1[i])) {
//             common1.push_back(seq1[i]);
//         }
//     }
//     for (int i = 0; i < (int)seq2.size(); i++) {
//         if (has(common1, seq2[i])) {
//             common2.push_back(seq2[i]);
//         }
//     }
//     size1 = (long)common1.size();
//     size2 = (long)common2.size();
//     for (int i = 0; i < size1; i++) {
//         cout << common1[i] << " ";
//     }
//     cout << endl;
//     for (int i = 0; i < size2; i++) {
//         cout << common2[i] << " ";
//     }
//     cout << endl;
//
//     for (int i = 0; i <= size1; i++) {
//         for (int j = 0; j <= size2; j++) {
//             if (i * j == 0)
//                 lcss[i][j] = 0;
//             else if (common1[i-1] == common2[j-1]) {  // match!
//                 cout << " match " << common2[j-1] << endl;
//                 if (common2[pin] < common2[j-1]) {
//                     lcss[i][j] = lcss[i-1][j-1] + 1;
//                     if (j-1 > pin || (temp_seq.size() == 1)) {
//                         prevpin = pin;
//                         pin = j-1;
//                     }
//                     cout << " pin " << common2[pin] << endl;
//                 }
//                 else if (common2[pin] > common2[j-1] && common2[j-1] >= common2[prevpin]) {
//                     cout << j-1 << " " << pin <<endl;
//                     if (j-1 > pin) {
//                         prevpin = pin;
//                         pin = j-1;
//                     }
//                     cout << " pin2 " <<common2[pin] << endl;
//                 }
//                 lcss[i][j] = max(max(lcss[i][j], 1), max(lcss[i-1][j], lcss[i][j-1]));
//             }
//             else
//                 lcss[i][j] = max(lcss[i-1][j], lcss[i][j-1]);
//         }
//     }
//     for (int i = 0; i < size1 + 1; i++) {
//       for (int j = 0; j < size2 + 1; j++) {
//         cout << lcss[i][j] << " ";
//       }
//
//       // Newline for new row
//       cout << endl;
//     }
//     return to_string(lcss[size1][size2]) + '\n';
// }

vector<int> cinToVector() {

    int num;
    string line;
    getline(cin, line);
    istringstream ss(line);
    vector<int> seq;

    while (ss >> num)
        seq.push_back(num);
    return seq;
}

vector_map cinToVectorMap() {

    int num;
    string line;
    getline(cin, line);
    istringstream ss(line);
    vector<int> seqv;
    unordered_map<int, int> seqm;

    while (ss >> num) {
        seqv.push_back(num);
        seqm.insert(make_pair(num, NULL));
    }
    return {seqv, seqm};
}

vector_map cinToVectorMapExcept(const unordered_map<int, int> &seq1) {

    int num;
    string line;
    getline(cin, line);
    istringstream ss(line);
    vector<int> seq2v;
    unordered_map<int, int> seq2m;

    while (ss >> num) {
        if (seq1.count(num)) {
            seq2v.push_back(num);
            seq2m.insert(make_pair(num, NULL));
        }
    }
    return {seq2v, seq2m};
}

void VectorExcept(vector<int> &seq1v, unordered_map<int, int> &seq2m) {

    int i = 0;
    vector<int>::iterator it = seq1v.begin();
    while (it != seq1v.end()) {
        if (seq2m.count(seq1v[i])) {
            it++;
            i++;
        }
        else
            it = seq1v.erase(it);
    }
}