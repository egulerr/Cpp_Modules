#include <iostream>
#include <deque>
#include <vector>

class PmergeMe {
    public:
        std::vector<int> vec_array;
        std::deque<int> deq_array;

        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &ref);
        PmergeMe& operator=(const PmergeMe &ref);

        int checkArgs(char **av);
        void fillContainers(char **av);
};