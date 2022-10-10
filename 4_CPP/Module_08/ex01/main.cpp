
#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span err_span = Span(10);

    try {
        std::cout << err_span.shortestSpan() << std::endl;
        std::cout << err_span.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        for (int i = 0; i < 15; ++i) {
            err_span.addNumber(1);
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Span span = Span(10);
    span.addNumber(5);
    span.addNumber(12);
    span.addNumber(22);
    span.addNumber(17);
    span.addNumber(25);

    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;

    Span big_span = Span(20000);

    std::vector<int> tmp_vec;
    for (int i = 0; i < 13000; i++) {
        tmp_vec.push_back(i * 2);
    }

    try {
        big_span.addNumber(tmp_vec.begin(), tmp_vec.end());
        std::cout << big_span.shortestSpan() << std::endl;
        std::cout << big_span.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}