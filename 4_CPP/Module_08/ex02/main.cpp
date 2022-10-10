
#include "MutantStack.hpp"
#include "list"

int main() {
    std::cout << " - Mutant Stack - " << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(1337);
    mstack.push(42);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }


    std::cout << " - List - " << std::endl;

    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(1337);
    mlist.push_back(42);
    mlist.push_back(0);

    std::list<int>::iterator it2 = mlist.begin();
    std::list<int>::iterator ite2 = mlist.end();
    ++it2;
    --it2;
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::cout << " - Vector - " << std::endl;

    std::list<int> mvect;
    mvect.push_back(5);
    mvect.push_back(17);
    std::cout << mvect.back() << std::endl;
    mvect.pop_back();
    std::cout << mvect.size() << std::endl;
    mvect.push_back(3);
    mvect.push_back(5);
    mvect.push_back(737);
    mvect.push_back(1337);
    mvect.push_back(42);
    mvect.push_back(0);

    std::list<int>::iterator it3 = mvect.begin();
    std::list<int>::iterator ite3 = mvect.end();
    ++it3;
    --it3;
    while (it3 != ite3) {
        std::cout << *it3 << std::endl;
        ++it3;
    }

    return 0;
}