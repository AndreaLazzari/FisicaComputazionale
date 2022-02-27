#ifndef SOLIDO_HH
#define SOLIDO_HH

class Solido {
public:
    Solido();
    virtual double volume() = 0;
    virtual double superficie() = 0;
};

#endif // SOLIDO_HH
