// Advent of Code 2022
// By @JordanXion

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int PartOne()
{
	std::ifstream input("input.txt");

	if (!input.is_open())
	{
		std::cerr << "Error: failed to open input.txt" << std::endl;
		return 1;
	}

	int total_sum = 0;

	std::string line;
	while (std::getline(input, line))
	{
		int halfLen = line.length() / 2;
		std::string one = line.substr(0, halfLen);
		std::string two = line.substr(halfLen, std::string::npos);
		char dupe;
		for (int i = 0; i < halfLen; i++)
		{
			if (two.find(one[i]) != std::string::npos)
			{
				//std::cout << "Found: " << one[i] << std::endl;
				dupe = one[i];
				if ((int)dupe > 96)
				{
					total_sum += ((int)dupe) - 96;
				}
				else
				{
					total_sum += ((int)dupe) - 38;
				}
				break;
			}
		}
		
		
		
	}
	input.close();

	return total_sum;
}

int PartTwo()
{
	std::ifstream input("input.txt");

	if (!input.is_open())
	{
		std::cerr << "Error: failed to open input.txt" << std::endl;
		return 1;
	}

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(input, line))
	{
		lines.push_back(line);
	}
	input.close();

	int total_sum = 0;

	for (int i = 0; i < lines.size(); i += 3)
	{
		for (int j = 0; j < lines[i].length(); j++)
		{
			if (lines[i+1].find(lines[i][j]) != std::string::npos &&
				lines[i+2].find(lines[i][j]) != std::string::npos)
			{
				char badge = lines[i][j];
				if ((int)badge > 96)
				{
					total_sum += ((int)badge) - 96;
				}
				else
				{
					total_sum += ((int)badge) - 38;
				}
				break;
			}
		}
	}

	return total_sum;
}

int main()
{
	std::cout << "Advent of Code Day 2: Rock Paper Scissors" << std::endl;
	std::cout << "By @JordanXion" << std::endl;
	std::cout << std::string(80, '-') << std::endl << std::endl;

	
	std::cout << "Part 1: Total score: " << PartOne() << std::endl;
	std::cout << "Part 2: Total score: " << PartTwo() << std::endl;

	return 0;
}

