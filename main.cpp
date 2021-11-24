#include <iostream>
#include <LinkedList/LinkedList.hpp>

int main() {
    LinkedList<int> l {1, 2, 3, 4, 5};
    l.push_back(213);
    l.push_front(123);

    for (auto i : l) {
        std::cout << i << ' ';
    }
    return 0;
}
