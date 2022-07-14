
#include <iostream>

struct Data{
    std::string	_str;
    int	_num;
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data *before = new Data;
    Data *after;
    uintptr_t ptr;

    before->_str = "Hello";
    before->_num = 322;

    std::cout << before << " : " << before->_str << ", " << before->_num<< std::endl;

    ptr = serialize(before);
    after = deserialize(ptr);

    std::cout << after << " : " << after->_str << ", " << after->_num<< std::endl;
    return (0);
}