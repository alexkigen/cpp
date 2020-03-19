//demonstrate sort function

#include <iostream>
#include <vector>


using namespace std;

int main () {
    vector<string> words;

    for (string word; cin >> word; ) {
        words.push_back(word);
    }

    cout << "Number of words: " << words.size() << endl;
    cout << words[2] << endl;

    sort(words.begin(), words.end());

    for (int i = 0; i < words.size(); ++i) {
        if (i == 0 || words[i-1] != words[i]) {
            cout << words[i] << endl;
        } else {
            
        }
    }

}
