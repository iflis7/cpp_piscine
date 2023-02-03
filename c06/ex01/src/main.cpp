#include "../include/Data.hpp"

uintptr_t serialize(Data *ptr)
{
    uintptr_t r;

    r = reinterpret_cast<uintptr_t>(ptr);
    return (r);
}

Data *deserialize(uintptr_t raw)
{
    Data *ptr;

    ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}

int main(void)
{
    std::cout << std::setw(30) << "==== ============ ====" << std::endl;

    uintptr_t r;
    Data d("Azul");
    Data *ptr;

    std::cout << std::setw(30) << "==== ====Test==== ====" << std::endl;

    std::cout << "addr d   = " << &d << std::endl;
    r = serialize(&d);
    std::cout << "Value r = " << r << std::endl;
    ptr = deserialize(r);
    std::cout << "addr ptr = " << ptr << std::endl;

    std::cout << "\n\t ============================== " << std::endl;
}
