#include "main.hpp"

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

    // Open the output file for writing
    string filename = string(argv[1]) + ".replace";
    ofstream outputFile(filename.c_str());

    // Check if the file was successfully opened
    if (!outputFile.is_open())
    {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }

    // Replace all occurrences of s1 with s2 in the input file and write the result to the output file
    replaceInFile(inputFile, outputFile, argv[2], argv[3]);

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}
