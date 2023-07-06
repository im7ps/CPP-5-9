/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:54:34 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/06 15:14:38 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(const std::string& token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool isNumber(const std::string& token)
{
    if (token.empty())
    {
        return false;
    }

    std::istringstream iss(token);
    int number;
    char remaining;
    return (iss >> number && !(iss >> remaining));
}

long long evaluateRPN(const std::string& expression)
{
    std::istringstream iss(expression);
    std::stack<long long> numbers;
    std::string token;

    while (iss >> token)
    {
        if (isOperator(token))
        {
            if (numbers.size() < 2)
            {
                throw std::runtime_error("Insufficient operands\n");
            }

            long long operand2 = numbers.top();
            numbers.pop();

            long long operand1 = numbers.top();
            numbers.pop();

            long long result;
            if (token == "+")
            {
                result = operand1 + operand2;
            }
            else if (token == "-")
            {
                result = operand1 - operand2;
            }
            else if (token == "*")
            {
                result = operand1 * operand2;
            }
            else if (token == "/")
            {
                if (operand2 == 0)
                {
                    throw std::runtime_error("Division by zero\n");
                }
                result = operand1 / operand2;
            }

            numbers.push(result);
        }
        else if (isNumber(token))
        {
            long long number;
            number = std::stoll(token);
            numbers.push(number);
        }
        else
        {
            throw std::runtime_error("Invalid token\n");
        }
    }

    if (numbers.size() != 1)
    {
        throw std::runtime_error("Invalid expression\n");
    }

    return numbers.top();
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        std::cout << "Usage: " << argv[0] << " \"<expression>\"\n";
        return 1;
    }

    std::string expression = argv[1];
    try
    {
        long long result = evaluateRPN(expression);
        std::cout << result << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what();
    }

    return 0;
}

