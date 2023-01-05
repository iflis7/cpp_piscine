#include "main.hpp"

/**
 * @brief Replaces all occurrences of s1 with s2 in the input file and writes the result to the output file.
 *
 * @param inputFile The input file.
 * @param outputFile The output file.
 * @param s1 The string to replace.
 * @param s2 The string to replace with.
 */
void replaceInFile(ifstream &inputFile, ofstream &outputFile, const string &s1, const string &s2)
{
    // Read the input file line by line
    string line;
    while (getline(inputFile, line))
    {
        // Replace every occurrence of s1 with s2
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != string::npos)
        {
            // Extract the part of the string before the occurrence of s1
            string before = line.substr(0, pos);

            // Extract the part of the string after the occurrence of s1
            string after = line.substr(pos + s1.length());

            // Concatenate the parts before and after s1 with s2
            line = before + s2 + after;

            // Update the position for the next search
            pos += s2.length();
        }

        // Write the modified line to the output file
        outputFile << line << endl;
    }
}
