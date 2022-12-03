// Advent of Code 2022
// By @JordanXion


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::cout << "Advent of Code Day 1: Calorie Counting" << std::endl;
	std::cout << "By @JordanXion" << std::endl;
	std::cout << std::string(80, '-') << std::endl << std::endl;

	std::ifstream input("input.txt");

	if (!input.is_open())
	{
		std::cerr << "Error: failed to open input.txt" << std::endl;
		return 1;
	}

	std::vector<int> elves;
	
	std::string line;
	int temp_total = 0;
	while (std::getline(input, line))
	{
		if (line.empty())
		{
			elves.push_back(temp_total);
			temp_total = 0;
		}
		else
		{
			temp_total += std::stoi(line);
		}
	}

	input.close();

	int most_calories_value = 0;
	for (int i = 0; i < elves.size(); i++)
	{
		if (elves[i] > most_calories_value)
		{
			most_calories_value = elves[i];
		}
		
		std::cout << "Elf " << i + 1 << " is carrying " << elves[i] << " Calories." << std::endl;
	}
	
	std::cout << std::endl << "Part 1: Highest calories value is " << most_calories_value << std::endl;

	//PART 2
	std::sort(elves.begin(), elves.end(), std::greater<int>());
	int top_three_value = elves[0] + elves[1] + elves[2];
	std::cout << std::endl << "Part 2: Top 3 combined value is " << top_three_value << std::endl;
	
	
	return 0;
}
