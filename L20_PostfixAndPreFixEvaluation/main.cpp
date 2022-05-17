#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperand(char c)
{
    return (c >= '0' && c <= '9');
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
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
    std::stack<int> s;
    std::string numToPush;

    for (int i = 0; i < expr.length(); i++)
    {
        if (isOperand(expr[i]))
        {
            // Reset the string when pushing a new Operand
            numToPush.clear();
            numToPush += expr[i];

            // Until, we get a delimiter and if it is a Operand,
            // keep adding it to the string
            while (isOperand(expr[++i]))
            {
                numToPush += expr[i];
            }

            // Push it to Stack after converting string to int
            s.push(stoi(numToPush));
        }
        else if (isOperator(expr[i]))
        {
            // Check for Edge cases where the input expression might be invalid
            //  IN that case, stack might not have expected operands
            int op1 = 0;
            int op2 = 0;
            if (!s.empty())
            {
                // Since we are traversing left to right,
                // Top of stack will be Operand 2
                op2 = s.top();
                s.pop();
            }
            else
            {
                return -1;
            }

            if (!s.empty())
            {
                op1 = s.top();
                s.pop();
            }
            else
            {
                return -1;
            }

            int result = performOperation(op1, op2, expr[i]);
            s.push(result);
        }
    }
    return s.top();
}

int evaluatePrefix(const std::string &expr)
{
    std::stack<char> s;
    std::string numToPush = "";
    int len = expr.length() - 1;
    for (int i = len; i >= 0; i--)
    {
        if (isOperand(expr[i]))
        {
            // Clear the string which will be pushed as Int to Stack
            numToPush.clear();
            // Add to string one character at a time
            numToPush += expr[i];

            // As long as there is an Operand character, keep adding to string
            while (isOperand(expr[--i]))
            {
                numToPush += expr[i];
            }
            // Since we are traversing from Left to Right, we need to reverse the string to get the real value
            std::reverse(numToPush.begin(), numToPush.end());
            s.push(stoi(numToPush));
        }
        else if (isOperator(expr[i]))
        {
            // Check for Edge cases where the input expression might be invalid
            //  In that case, stack might not have expected operands
            int op1 = 0;
            int op2 = 0;
            if (!s.empty())
            {
                op1 = s.top();
                s.pop();
            }
            else
            {
                return -1;
            }

            if (!s.empty())
            {
                op2 = s.top();
                s.pop();
            }
            else
            {
                return -1;
            }

            int result = performOperation(op1, op2, expr[i]);
            s.push(result);
        }
    }
    return s.top();
}

int main()
{
    std::string PostFixStr = "33 4 2 / 80 * + 66 -";
    std::string PreFixStr = "- + * / 4 2 80 33 66";

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

//    33+4/2*80-66
//  = 33+(4/2)*80-66
//  = 33+2*80-66
//  = 33+(2*80)-66
//  = 33+160-66
//  = 193-66
//  = 127

// Infix to Postfix
//   = 33 4 2 / 80 * + 66 -

// Infix to Postfix
//   = 33 4 2 / 80 * + 66 -