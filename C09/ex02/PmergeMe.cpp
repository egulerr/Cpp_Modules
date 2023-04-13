#include "PmergeMe.hpp"
#include <malloc/malloc.h>


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
    for (size_t i = 1; av[i] != NULL; i++) {
        int num = std::stoi(av[i]);
        vec_array.push_back(num);
		deq_array.push_front(num);
    }
}

template<typename T>
void PmergeMe::insertionSort(T& container) {
    if (std::string(typeid(container).name()).find("deque") != std::string::npos) {
        for (size_t i = 1; i < container.size(); i++) {
           	int temp = container[i];
            size_t j = i;
            while (j > 0 && container[j-1] >= temp) {
                container[j] = container[j-1];
                j--;
            }
            container[j] = temp;
        }
    }
    else {
        for (size_t i = 1; i < container.size(); i++) {
			int temp = container[i];
            int j = i - 1;
            while (j >= 0 && container[j] > temp) {
                container[j + 1] = container[j];
                j--;
            }
            container[j + 1] = temp;
        }
    }
}

void PmergeMe::displayContainer() {
    for (size_t i = 0; i < vec_array.size(); i++) {
        if (i >= 10) {
            std::cout << "[...]";
            break;
        }
        std::cout << vec_array[i] << " ";
    }
}

void PmergeMe::sortAndMeasure() {
    {
        std::cout << "Before: ";
        displayContainer();

        std::clock_t start = std::clock();
        mergeInsertSort(vec_array, 10);
        std::clock_t end = std::clock();
        double duration = (end - start) / (double)CLOCKS_PER_SEC * 1000000;

        std::cout << "\n" << "After: ";
        displayContainer();

        std::cout << "\n" << "Time to process a range of " << vec_array.size() << " elements with std::vector "
        << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
    }
    {
        std::clock_t start = std::clock();
        mergeInsertSort(deq_array, 10);
        std::clock_t end = std::clock();
        double duration = (end - start) / (double)CLOCKS_PER_SEC * 1000000;
        std::cout << "Time to process a range of " << deq_array.size() << " elements with std::deque "
        << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
    }
}

template<typename T>
void PmergeMe::mergeInsertSort(T& container, size_t threshold) {
    size_t len = container.size();
    if (len <= threshold) {
        insertionSort(container);
        return;
    }
    typename T::iterator begin = container.begin();
    typename T::iterator mid = container.begin() + container.size() / 2;
    typename T::iterator end = container.end();
    T left_subcontainer(begin, mid);
    T right_subcontainer(mid, end);

    mergeInsertSort(left_subcontainer, threshold);
    mergeInsertSort(right_subcontainer, threshold);
    std::merge(left_subcontainer.begin(), left_subcontainer.end(),
               right_subcontainer.begin(), right_subcontainer.end(),
               container.begin());
}