#include "../include/Data.hpp"

int test1(void)
{
    std::cout << std::setw(30) << "==== ======1====== ====" << std::endl;
    uintptr_t tmp;
    Data data("Azul");
    Data *tmpPtr = &data;

    std::cout << std::endl
              << std::setw(30) << "==== ====Test==== ====" << std::endl;
    std::cout << "addr data         = " << &data << std::endl;

    tmp = serialize(&data);
    std::cout << "Value tmp         = " << tmp << std::endl;

    Data *deser_ptr = deserialize(tmp);
    std::cout << "addr deser_ptr    = " << deser_ptr << std::endl
              << std::endl;

    if (deser_ptr == tmpPtr)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed." << std::endl;

    std::cout << std::setw(30) << "==== ============ ====" << std::endl;
    return (0);
}

int test2(void)
{
    std::cout << std::setw(30) << "==== ======2====== ====" << std::endl;
    uintptr_t tmp;
    Data data(23);
    Data *tmpPtr = &data;

    std::cout << std::endl
              << std::setw(30) << "==== ====Test==== ====" << std::endl;
     std::cout << "addr data         = " << &data << std::endl;

    tmp = serialize(&data);
    std::cout << "Value tmp         = " << tmp << std::endl;

    Data *deser_ptr = deserialize(tmp);
    std::cout << "addr deser_ptr    = " << deser_ptr << std::endl
              << std::endl;

    if (deser_ptr == tmpPtr)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed." << std::endl;

    std::cout << std::setw(30) << "==== ============ ====" << std::endl;
    // test1();
    return (0);
}

int main()
{
    test1();
    std::cout << std::endl
              << std::endl;
    test2();
    return (0);
}
