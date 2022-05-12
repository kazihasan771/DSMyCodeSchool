#include <iostream>
#include <stack>
using namespace std;

bool isCorrespondingParen(char left, char right)
{
    if (left == '(' && right == ')')
    {
        return true;
    }
    if (left == '{' && right == '}')
    {
        return true;
    }
    if (left == '[' && right == ']')
    {
        return true;
    }
    return false;
}

bool is_balanced_paren(string s)
{
    stack<char> st;
    // Start scanning from Left to Right
    for (int i = 0; i < s.length(); i++)
    {
        // Push if it is an "Opening Parenthesis"
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            // Stack is empty OR Top(closing parenthesis)  does not pair with
            // the parenthesis we are currently scanning in expression
            if (st.empty() || !isCorrespondingParen(st.top(), s[i]))
            {
                return false;
            }
            // Top pairs with current parenthesis, so remove from list
            st.pop();
        }
        else
        {
            // Skip any other char
            continue;
        }
    }

    return st.empty();
}

int main()
{
    std::string s = ")(";
    std::string s2 = "{(891273-43289[{asda}]())}";

    if (is_balanced_paren(s))
    {
        cout << s << " is balanced" << endl;
    }
    else
    {
        cerr << s << " is NOT balanced" << endl;
    }

    if (is_balanced_paren(s2))
    {
        cout << s2 << " is balanced" << endl;
    }
    else
    {
        cerr << s2 << " is NOT balanced" << endl;
    }

    return 0;
}