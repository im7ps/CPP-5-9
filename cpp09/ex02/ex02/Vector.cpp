#include "Vector.hpp"

// Funzione per l'unione di due vettori ordinati
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> merged;
    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
        }
    }

    // Aggiungi gli elementi rimanenti, se presenti
    while (i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }
    return merged;
}

// Funzione per l'ordinamento merge-insertion
std::vector<int> mergeInsertionSort(const std::vector<int>& array) {
    if (array.size() <= 1) {
        return array;
    }
    // Divide l'array a metà
    size_t mid = array.size() / 2;
    std::vector<int> left(array.begin(), array.begin() + mid);
    std::vector<int> right(array.begin() + mid, array.end());

    // Ordina ricorsivamente le due metà
    left = mergeInsertionSort(left);
    right = mergeInsertionSort(right);

    // Unisci le due metà ordinate
    return merge(left, right);
}
