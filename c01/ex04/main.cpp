#include "main.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments was provided
    if (argc != 4)
    {
        cerr << "Error: Invalid number of arguments." << endl;
        cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << endl;
        return 1;
    }

    // Open the input file for reading
    ifstream inputFile(argv[1]);

    // Check if the file was successfully opened
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    
    return 0;
}
