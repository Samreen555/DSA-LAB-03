#include<iostream>
#include<cstdlib>
#include<string> // using for getline 
#include<algorithm>  // using for reverse function 
#include<stack> // used for the built-in stack functions
using namespace std;
class Stack  //stack claass
{
private:
    int* arr;  // pointer for array
    int capacity;
    int top;

public:
    Stack(int size = 10)   // Constructor with default size of 10
    {
        capacity = size;   // Initialize capacity
        arr = new int[capacity];  // Allocate memory for array
        top = -1;          // Initialize top to -1 (empty stack)
    }

    ~Stack()     // Destructor
    {
        delete[] arr;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    bool push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = value;
        return true;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return false;
        }
        top--;
        return true;
    }

    void display() const {
        cout << "Displaying the stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool isoperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    int precedence_checker(char op) {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '^')
            return 3;
        else
            return 0;
    }

    // Infix to postfix conversion implementation
    string infix_to_postfix(string infix)
    {
        int start = 0;
        string postfix = "";
        stack <char>s;

        while (infix[start] != '\0')
        {
            // If operand, add to the postfix expression
            if (isalpha(infix[start])) {
                postfix += infix[start];
            }
            else if (infix[start] == '(') {
                s.push(infix[start]);
            }
            else if (infix[start] == ')') {
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                s.pop();
            }
            else {
                // Operator handling
                while (!s.empty() && precedence_checker(infix[start]) <= precedence_checker(s.top())) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(infix[start]);
            }
            start++;
        }

        // Pop remaining operators
        while (!s.empty()) {
            postfix += s.top();
            s.pop();
        }

        cout << "Postfix is : "<<postfix;
        return postfix;
    }
    string reverse_string(string exp)
    {
        reverse(exp.begin(), exp.end());
        return exp;
    }
    string infix_to_prefix(string infix)
    {
        string postfix, prefix;
        // Reverse the infix expression
        infix = reverse_string(infix);
        for (int i = 0; i < infix.length(); i++)
        {
            if (infix[i] == '(') // ( agar ye aye tu ) kar dy
                infix[i] = ')';
            else if (infix[i] == ')')
                infix[i] = '(';
        }

        // Getting the postfix of the change infix expression
        postfix = infix_to_postfix(infix);

        // Reverse the postfix to get the prefix expression
        prefix = reverse_string(postfix);

        cout << "Prefix is: " << prefix << endl;
        return prefix;
    }

};
int power(int x, int n)
{
    int conclusion;
    if (n == 0)
    {
        return 1;
    }
    else
        conclusion = (x * power(x, n - 1));
    return conclusion;
}
int multiply(int a, int b)
{
    int result;
    if (b == 1) {
        return a;
    }
    else
        result = multiply(a, b - 1) + a;
    return result;
}
// Main program
int main()
{
    Stack st;
    string expression, exp, infix;
    int choice;
    do {
        cout << "Menu-based task:" << endl;
        cout << "1. Infix expression to prefix conversion: " << endl;
        cout << "2. Infix expression to postfix conversion: " << endl;
        cout << "3. Multiplication of two numbers:" << endl;
        cout << "4. Computing power of a number:" << endl;
        cout << "5. Exit the program: " << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        // Ignore the leftover newline character from previous input
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter the expression for prefix conversion: " << endl;
            getline(cin, exp);
            st.infix_to_prefix(exp);
            cout << "\n ---------------------------------------------------------------------------";
            break;

        case 2:
            cout << "Enter the expression for postfix conversion: " << endl;
            getline(cin, expression);  // Get the infix expression from the user
            st.infix_to_postfix(expression);  // Convert and display postfix expression
            cout << "\n ---------------------------------------------------------------------------";
            break;

        case 3:
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result: " << a * b << endl;
            cout << "\n ---------------------------------------------------------------------------";
            break;

        case 4:
            int x, n;
            cout << "Enter the number: ";
            cin >> x;
            cout << "Enter the power: ";
            cin >> n;
            cout << "Result: " << power(x, n) << endl;
            cout << "\n ---------------------------------------------------------------------------";
            break;

        case 5:
            cout << "Exiting the program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        cout << endl;

    } while (choice != 5);
    system("pause");
    return 0;
}