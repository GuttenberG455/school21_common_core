
#include "ASpell.hpp"

class Polymorph {
public:
    Polymorph();
    ~Polymorph();

    virtual ASpell *clone() const;
};


