/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:26:23 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/06 17:25:52 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//per usare jot bisogna lanciarlo come un comando da espandere, ex:
//./PmergeMe $(jot -r 3000 1 100000 | tr '\n' ' ')

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        std::cout << "No input sequence provided." << std::endl;
        return 0;
    }
    
    std::vector<int> inputVector;
    for (int i = 1; i < argc; ++i)
    {
        int num = std::atoi(argv[i]);
        if (num <= 0)
        {
            std::cout << "Invalid input: " << argv[i] << std::endl;
           return 0;
        }
        inputVector.push_back(num);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < inputVector.size(); ++i)
    {
        std::cout << inputVector[i] << " ";
    }
    std::cout << std::endl;
    
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedVector = mergeInsertionSort(inputVector);
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::deque<int> inputDeque;
    for (size_t i = 0; i < inputVector.size(); ++i)
    {
        inputDeque.push_back(inputVector[i]);
    }
    
    std::chrono::high_resolution_clock::time_point startTime2 = std::chrono::high_resolution_clock::now();
    std::deque<int> sortedDeque = mergeInsertionSort2(inputDeque);
    std::chrono::high_resolution_clock::time_point endTime2 = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration2 = std::chrono::duration_cast<std::chrono::microseconds>(endTime2 - startTime2);
    
    std::cout << "After: ";
    std::deque<int>::iterator it;
    for (it = sortedDeque.begin(); it != sortedDeque.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector: " << duration.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::deque: " << duration2.count() << " us" << std::endl;
    
    return 0;
}