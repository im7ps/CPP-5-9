#include "Deque.hpp"

// Funzione per l'unione di due std::deque ordinati
std::deque<int> merge2(const std::deque<int>& left, const std::deque<int>& right) {
    std::deque<int> merged;
    std::deque<int>::const_iterator leftIt = left.begin();
    std::deque<int>::const_iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt <= *rightIt) {
            merged.push_back(*leftIt);
            ++leftIt;
        } else {
            merged.push_back(*rightIt);
            ++rightIt;
        }
    }

    // Aggiungi gli elementi rimanenti, se presenti
    while (leftIt != left.end()) {
        merged.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != right.end()) {
        merged.push_back(*rightIt);
        ++rightIt;
    }

    return merged;
}

// Funzione per l'ordinamento merge-insertion
std::deque<int> mergeInsertionSort2(const std::deque<int>& inputDeque) {
    if (inputDeque.size() <= 1) {
        return inputDeque;
    }

    // Dividi il deque a metà
    std::deque<int> left;
    std::deque<int> right;
    std::deque<int>::const_iterator it = inputDeque.begin() + inputDeque.size() / 2;

    left.insert(left.begin(), inputDeque.begin(), it);
    right.insert(right.begin(), it, inputDeque.end());

    // Ordina ricorsivamente le due metà
    left = mergeInsertionSort2(left);
    right = mergeInsertionSort2(right);

    // Unisci le due metà ordinate
    return merge2(left, right);
}

