#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* next;
    Node(char val) : value(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}
    
    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    
    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    char peek() {
        return top ? top->value : '\0';
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
};

bool isValid(string s) {
    Stack st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.isEmpty()) return false;
            char top = st.peek();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
            st.pop();
        }
    }
    return st.isEmpty();
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}
