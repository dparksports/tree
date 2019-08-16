#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Palindrome {

private:
    stack<char> charStack;
    queue<char> charQueue;

public:
    void pushCharacter(const char letter) {
        charStack.push(letter);
    }
    char popCharacter() {
        char top = charStack.top();
        charStack.pop();
        return top;
    }

    void enqueueCharacter(const char letter) {
        charQueue.push(letter);
    }
    char dequeueCharacter() {
        char front = charQueue.front();
        charQueue.pop();
        return front;
    }

};

int main() {
    // read the string s.
    string s;
    getline(cin, s);

    // create the Solution class object p.
    Palindrome obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}
