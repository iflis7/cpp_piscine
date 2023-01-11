#include "main.hpp"

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments was provided
    if (argc != 4)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    // Open the input file for reading
    std::ifstream inputFile(argv[1]);

    // Check if the file was successfully opened
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file for reading." << std::endl;
        return 1;
    }

    // Open the output file for writing
    std::string filename = std::string(argv[1]) + ".replace";
   std::ofstream outputFile(filename.c_str());

    // Check if the file was successfully opened
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return 1;
    }

    // Replace all occurrences of s1 with s2 in the input file and write the result to the output file
    replaceInFile(inputFile, outputFile, argv[2], argv[3]);

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}

