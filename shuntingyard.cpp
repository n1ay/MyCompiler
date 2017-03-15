/*
 * shuntingyard.cpp
 *
 *  Created on: 15.03.2017
 *      Author: kamil
 *
 *  Implementation of the shunting-yard algorithm
 *  that converts equation from infix to postfix (Reversed Polish Notation)
 *
 */

#include "shuntingyard.hpp"

/*
 * Postfix notation uses space as a delimiter
 * 12+3 -> 12 3 +
 */
std::string toPostfix(std::string infix) {
	std::string result;
	std::stack<std::string> stack;
	std::string number;

	int length = infix.length();

	for(int i=0; i<length;) {
		if(isdigit(infix[i])) {
			while(isdigit(infix[i]) || infix[i] == '.') {
				number += infix[i];
				i++;
			}
			result += number + " ";
			number = "";
		} else if (infix[i] == '(') {
			stack.push("(");
			i++;
		} else if (infix[i] == ')') {
			while(!stack.empty() && stack.top()!="(") {
				result += stack.top() + " ";
				stack.pop();
			}
			stack.pop();
			i++;
		} else if (infix[i] == '+' || infix[i]  == '-') {
			if(i == 0 || infix[i-1] == '(') {
				result += "0 ";
			} else {
				while(!stack.empty() && hasOperatorLowerPrecedence(stack.top(), 1)) {
					result += stack.top() + " ";
					stack.pop();
				}
			}
				stack.push(std::string(1, infix[i]));
				i++;
		} else if (infix[i] == '*' || infix[i] == '/') {
			while(!stack.empty() && hasOperatorLowerPrecedence(stack.top(), 2)) {
							result += stack.top() + " ";
							stack.pop();
						}
			stack.push(std::string(1, infix[i]));
			i++;
		}
	}

	while(!stack.empty()) {
		if(stack.top() == "(") {
			std::cerr<<"Parenthesis error"<<std::endl;
			exit(-1);
		}
		result += stack.top() + " ";
		stack.pop();
	}

	return result;
}

bool hasOperatorLowerPrecedence(std::string op, int precedence) {
	switch(precedence) {
	case 1:
		return (op == std::string("+")) + (op == std::string("-")) + (op == std::string("*")) + (op == std::string("/"));
		break;
	case 2:
		return (op == std::string("*")) + (op == std::string("/"));
		break;
	default:
		return false;
		break;
	}
}

double calculate(std::string postfix) {
	std::string symbol;
	std::stack<double> stack;
	int length = postfix.length();
	for(int i=0; i<length;) {
			if(isdigit(postfix[i])) {
				while(isdigit(postfix[i]) || postfix[i] == '.') {
					symbol += postfix[i];
					i++;
				}
				stack.push(stod(symbol));
				symbol = "";
			}
			else if (postfix[i] == ' ') {
				i++;
				continue;
			}
			else {
				double d1;
				double d2;
				if(!stack.empty()) {
					d1 = stack.top();
					stack.pop();
					if(!stack.empty()) {
						d2 = stack.top();
						stack.pop();

						switch(postfix[i]) {
						case '+':
							d2 += d1;
							break;
						case '-':
							d2 -= d1;
							break;
						case '*':
							d2 *= d1;
							break;
						case '/':
							d2 /= d1;
							break;
						default:
							break;
						}

						stack.push(d2);
						i++;

					} else {
						std::cerr<<"Bad postfix expression"<<std::endl;
						exit(-1);
					}
				} else {
					std::cerr<<"Bad postfix expression"<<std::endl;
					exit(-1);
				}
			}
	}
	if(!stack.empty()) {
		return stack.top();

	} else {
		std::cerr<<"Stack empty at the end!"<<std::endl;
		exit(-1);
	}
}




