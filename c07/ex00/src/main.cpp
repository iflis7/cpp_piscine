#include "../include/Whatever.hpp"

int main(void)
{
    {
        std::cout << std::setw(30) << " ============ ============ " << std::endl;
        std::cout << std::setw(30) << " ========= Test Int ========= " << std::endl;
        int x = 42.0f;
        int y = 3.0f;

        ::ft_putvar(x, y); // Check before the swap
        ::swap(x, y);
        ::ft_putvar(x, y); // Check after the swap
        std::cout << "Min = " << ::min(x, y) << std::endl;
        std::cout << "Max = " << ::max(x, y) << std::endl;
    }
    return (0);
}
