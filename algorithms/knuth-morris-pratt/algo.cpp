#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& arr) {
    for_each(arr.begin(), arr.end(), [](int i) {
        cout << i << " ";
    })
    cout << endl;
}

void constructLPS(string& pattern, vector<int>& lps) {
    int len = 0, i = 1;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else if (len == 0) {
            lps[i] = 0;
            i++;
        } else {
            len = lps[len-1];
        }
    }
}

vector<int> search(string& text, string& pattern) {
    int i=0, j=0;
    vector<int> ans;
    vector<int> lps(pattern.size(), 0);
    constructLPS(pattern, lps);

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == pattern.length()) {
                ans.push_back(i-j);
                j = lps[j-1];
            }
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j-1];
            }
        }
    }

    return ans;
}

int main() {
    string text = "aabaacaadaabaaba", pattern = "ababaa";
    vector<int> ans;

    ans = search(text, pattern);
    printVector(ans);
}