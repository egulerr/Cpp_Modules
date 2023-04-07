#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &ref) { *this = ref; }

PmergeMe &PmergeMe::operator=(const PmergeMe &ref)
{
    if (this != &ref)
    {
        this->vec_array.insert(this->vec_array.end(), ref.vec_array.begin(), ref.vec_array.end());
        this->deq_array.insert(this->deq_array.end(), ref.deq_array.begin(), ref.deq_array.end());
    }
    return (*this);
}

int PmergeMe::checkArgs(char **av)
{
    for (size_t i = 1; av[i]; i++) {
        for (size_t j = 0; av[i][j]; j++) {
            if (isdigit(av[i][j]))
                continue;
            else
                return 0;
        }
    }
    fillContainers(av);
    return (1);
}

void PmergeMe::fillContainers(char **av) {
    for (size_t i = 1; av[i]; i++) {
        int num = std::stoi(av[i]);
        vec_array.push_back(num);
        deq_array.push_back(num);
    }
    sortAndMeasure();
    
}

template<typename T>
void PmergeMe::insertionSort(T& container) {
    for (typename T::size_type i = 1; i < container.size(); i++) {
        typename T::value_type temp = container[i];
        typename T::size_type j = i - 1;
        while (j >= 0 && container[j] > temp) {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = temp;
    }
}


void PmergeMe::sortAndMeasure() {
    std::chrono::high_resolution_clock::time_point vec_start_time = std::chrono::high_resolution_clock::now();
    mergeInsertSort(vec_array);
    std::chrono::high_resolution_clock::time_point vec_end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vec_elapsed_time = std::chrono::duration_cast<std::chrono::duration<double, std::micro> >(vec_end_time - vec_start_time);
    std::cout << "Time to process a range of " << vec_array.size() << " elements with vec: std::[..] : " << vec_elapsed_time.count() << " us" << std::endl;

    std::chrono::high_resolution_clock::time_point deq_start_time = std::chrono::high_resolution_clock::now();
    mergeInsertSort(deq_array);
    std::chrono::high_resolution_clock::time_point deq_end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> deq_elapsed_time = std::chrono::duration_cast<std::chrono::duration<double, std::micro> >(deq_end_time - deq_start_time);
    std::cout << "Time to process a range of " << deq_array.size() << " elements with deq: std::[..] : " << deq_elapsed_time.count() << " us" << std::endl;
}



template<typename T>
void PmergeMe::mergeInsertSort(T& container) {
    const int size = container.size();
    if (size == 2) {
        if (container[0] > container[1])
            std::swap(container[0], container[1]);
        return;
    }
    if (size <= 10){
        insertionSort(container);
        return ;
    }

    const int middle = size / 2;
    typename T::iterator middle_it = container.begin() + middle;
    T left_container(container.begin(), middle_it);
    T right_container(middle_it, container.end());
    
    mergeInsertSort(left_container);
    mergeInsertSort(right_container);
    
    T merged_container;
    typename T::const_iterator left_it = left_container.begin();
    typename T::const_iterator right_it = right_container.begin();
    
    while (left_it != left_container.end() && right_it != right_container.end()) {
        if (*left_it < *right_it) {
            merged_container.push_back(*left_it);
            ++left_it;
        } else {
            merged_container.push_back(*right_it);
            ++right_it;
        }
    }
    
    while (left_it != left_container.end()) {
        merged_container.push_back(*left_it);
        ++left_it;
    }
    
    while (right_it != right_container.end()) {
        merged_container.push_back(*right_it);
        ++right_it;
    }
    
    std::copy(merged_container.begin(), merged_container.end(), container.begin());
}