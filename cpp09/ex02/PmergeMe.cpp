/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:16:54 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/06 16:44:22 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right)
{
    std::vector<int> merged;
    size_t i = 0;
    size_t j = 0;
    

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[i])
        {
            merged.push_back(left[i]);
            ++i;
        }
        else
        {
            merged.push_back(right[j]);
            ++j;
        }
    }

    while (i < left.size())
    {
            merged.push_back(left[i]);
            ++i;
    }

    while (j < right.size())
    {
            merged.push_back(left[j]);
            ++j;
    }
    return merged;
}

std::vector<int> mergeInsertionSort(const std::vector<int>& inputVector)
{
    if (inputVector.size() <= 1)
        return inputVector;

    size_t mid = inputVector.size() / 2;

    std::vector<int> left(inputVector.begin(), inputVector.begin() + mid);
    std::vector<int> right(inputVector.begin() + mid, inputVector.end());
    
    left = mergeInsertionSort(left);
    right = mergeInsertionSort(right);

    return merge(left, right);
}

std::deque<int> merge2(const std::deque<int>& left, const std::deque<int>& right)
{
    std::deque<int> merged;
    std::deque<int>::const_iterator lefty = left.begin();
    std::deque<int>::const_iterator righty = right.begin();
    
    while (lefty != left.end() && righty != right.end())
    {
        if (*lefty <= *righty)
        {
            merged.push_back(*lefty);
            ++lefty;
        }
        else
        {
            merged.push_back(*righty);
            ++righty;
        }
    }

    while (lefty != left.end())
    {
        merged.push_back(*lefty);
        ++lefty;
    }

    while (righty != right.end())
    {
        merged.push_back(*righty);
        ++righty;
    }

    return merged;
}

std::deque<int> mergeInsertionSort2(const std::deque<int>& inputDeque)
{
    if (inputDeque.size() <= 1)
        return inputDeque;

    std::deque<int> left;
    std::deque<int> right;
    std::deque<int>::const_iterator it = inputDeque.begin() + inputDeque.size() / 2;

    left.insert(left.begin(), inputDeque.begin(), it);
    right.insert(right.begin(), it, inputDeque.end());
    
    left = mergeInsertionSort2(left);
    right = mergeInsertionSort2(right);

    return merge2(left, right);
}
