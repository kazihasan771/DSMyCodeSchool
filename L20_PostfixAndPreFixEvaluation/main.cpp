#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c)
{
    return (c >= '0' && c <= '9');
}

bool isOperator(char c)
{
    if (int(c) == '+' || int(c) == '-' || int(c) == '*' || int(c) == '/')
    {
        return true;
    }
    return false;
}

int performOperation(int op1, int op2, char c)
{
    int result = -1;
    switch (c)
    {
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op1 - op2;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '/':
        if (op2 == 0)
        {
            break;
        }
        result = op1 / op2;
        break;
    default:
        break;
    }
    return result;
}
int evaluatePostfix(const std::string &expr)
{
    std::stack<char> s;

    for (int i = 0; i < expr.length(); i++)
    {
        if (isOperand(expr[i]))
        {
            s.push(int(expr[i]) - '0');
        }
        else if (isOperator(expr[i]))
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int result = performOperation(op1, op2, expr[i]);
            std::cout << "op1: " << op1 << ", op2: " << op2 << ", operation" << expr[i] << std::endl;
            std::cout << "result: " << result << std::endl;
            s.push(result);
        }
    }
    return s.top();
}

int evaluatePrefix(const std::string &expr)
{
    std::stack<char> s;

    int len = expr.length() - 1;
    for (int i = len; i >= 0; i--)
    {
        if (isOperand(expr[i]))
        {
            s.push(int(expr[i]) - '0');
        }
        else if (isOperator(expr[i]))
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            int result = performOperation(op1, op2, expr[i]);
            std::cout << "op1: " << op1 << ", op2: " << op2 << ", operation" << expr[i] << std::endl;
            std::cout << "result: " << result << std::endl;
            s.push(result);
        }
    }
    return s.top();
}

int main()
{
    std::string PostFixStr = "3 4 2 / 8 * + 6 -";
    std::string PreFixStr = "- + * / 4 2 8 3 6";

    int AnswerPostFix = evaluatePostfix(PostFixStr);
    std::cout << "AnswerPostFix: " << AnswerPostFix << std::endl;

    int AnswerPreFix = evaluatePrefix(PreFixStr);
    std::cout << "AnswerPreFix: " << AnswerPreFix << std::endl;

    return 0;
}

//    3+4/2*8-6
//  = 3+(4/2)*8-6
//  = 3+2*8-6
//  = 3+(2*8)-6
//  = 3+16-6
//  = 19-6
//  = 13

// Infix to Postfix
//   = 3+{(4/2)*8}-6
//   = 3+{(4 2 /) * 8} -6
//   = 3+ {4 2 / 8 *} - 6
//   = (3 4 2 / 8 * +) - 6
//   = 3 4 2 / 8 * + 6 -

// Infix to Prefix
//   = 3+{(4/2)*8}-6
//   = 3 + { (/ 4 2) * 8 } - 6
//   = 3 + { * / 4 2 8 } - 6
//   = + * / 4 2 8 3 -6
//   = - + * / 4 2 8 3 6