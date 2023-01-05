#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

/**
 * @brief Replaces all occurrences of s1 with s2 in the input file and writes the result to the output file.
 *
 * @param inputFile The input file.
 * @param outputFile The output file.
 * @param s1 The string to replace.
 * @param s2 The string to replace with.
 */
void replaceInFile(std::ifstream &inputFile, std::ofstream &outputFile, const std::string &s1, const std::string &s2);

#endif
