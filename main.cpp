#include "Stack.h"
#include "Exceptions.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    
    Stack wordStack;
    string word;

    cout << "Enter a string: ";
    getline(cin, word);

    for (int i = (word.length()-1) ; i >=0 ; i--) {
        wordStack.push(word[i]);
    }

    if (wordStack.isBalanced()) {
        cout << "The string is balanced." << endl;
    } else {
        cout << "The string is not balanced." << endl;
    }

    return 0;

}