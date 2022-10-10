
#include <iostream>

class Base {
public:
    virtual ~Base() {};
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

class D : public Base {
};

Base *generate(void) {
    int r = rand() % 3;
    if (r == 0)
        return (new A);
    if (r == 1)
        return (new B);
    return (new C);
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Not a ABC" << std::endl;
}

void identify(Base &p) {
    try {
        (void) dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &ex) {};

    try {
        (void) dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &ex) {};

    try {
        (void) dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &ex) {};

    std::cout << "Not a ABC" << std::endl;
}


int main() {
    srand(time(NULL));

    Base *base1 = generate();
    Base *base2 = generate();

    Base *base3 = generate();
    Base *base4 = generate();

    std::cout << "Using pointer" << std::endl;

    identify(base1);
    identify(base2);

    std::cout << std::endl << "Using reference" << std::endl;

    identify(*base3);
    identify(*base4);

    D *d = new D;

    std::cout << std::endl << "Wrong class" << std::endl;

    identify(d);
    identify(*d);


    delete base1;
    delete base2;
    delete base3;
    delete base4;
    delete d;

    return (0);
}