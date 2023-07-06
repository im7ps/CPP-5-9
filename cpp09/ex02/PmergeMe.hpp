/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:16:51 by sgerace           #+#    #+#             */
/*   Updated: 2023/07/06 16:04:12 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
std::vector<int> mergeInsertionSort(const std::vector<int>& inputVector);

std::deque<int> merge2(const std::deque<int>& left, const std::deque<int>& right);
std::deque<int> mergeInsertionSort2(const std::deque<int>& inputDeque);

#endif