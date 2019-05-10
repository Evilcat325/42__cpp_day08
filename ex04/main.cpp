#include <string>
#include <stack>
#include <iostream>

//Function to return precedence of operators
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(std::string s)
{
	std::stack<char> st;
	st.push('N');
	int l = s.length();
	std::string ns;
	for (int i = 0; i < l; i++)
	{
		// If the scanned character is an operand, add it to output string.
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			ns += s[i];
		// If the scanned character is an ‘(‘, push it to the stack.
		else if (s[i] == '(')
			st.push('(');
		// If the scanned character is an ‘)’, pop and to output string from the stack
		// until an ‘(‘ is encountered.
		else if (s[i] == ')')
		{
			while (st.top() != 'N' && st.top() != '(')
			{
				ns += st.top();
				st.pop();
			}
			if (st.top() == '(')
				st.pop();
		}
		//If an operator is scanned
		else
		{
			while (st.top() != 'N' && prec(s[i]) <= prec(st.top()))
			{
				ns += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	//Pop all the remaining elements from the stack
	while (st.top() != 'N')
	{
		ns += st.top();
		st.pop();
	}

	std::cout << ns << std::endl;
}

// Driver code
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "expecting only one argument" << std::endl;
		return 0;
	}
	std::string infix = argv[1];
	infixToPostfix(infix);
	return 0;
}
