#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("DEBUG");
    cout << endl;
    harl.complain("INFO");
    cout << endl;
    harl.complain("WARNING");
    cout << endl;
    harl.complain("ERROR");
    return 0;
}
