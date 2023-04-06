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
}