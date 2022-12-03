// Advent of Code 2022
// By @JordanXion

#include "constants.h"
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

	int total_score = 0;

	std::string line;
	while (std::getline(input, line))
	{
		int opponent_move = (int)(line[0] - 64);
		int my_move = (int)(line[2] - 64 - 23);
		total_score += my_move;

		if (opponent_move == my_move)
		{
			total_score += SCORE_DRAW;
		}
		else if (opponent_move == my_move + 1 || opponent_move == my_move - 2)
		{
			total_score += SCORE_LOSS;
		}
		else
		{
			total_score += SCORE_WIN;
		}
	}
	input.close();

	return total_score;
}

int PartTwo()
{
	std::ifstream input("input.txt");

	if (!input.is_open())
	{
		std::cerr << "Error: failed to open input.txt" << std::endl;
		return 1;
	}

	int total_score = 0;

	std::string line;
	while (std::getline(input, line))
	{
		int opponent_move = (int)(line[0] - 64);
		int instruction = (int)(line[2] - 64 - 23);
		int my_move;
		
		if (instruction == LOSE)
		{
			my_move = opponent_move - 1;
			if (my_move == 0) { my_move = 3; }
		}
		else if (instruction == DRAW)
		{
			my_move = opponent_move;
		}
		else
		{
			my_move = opponent_move + 1;
			if (my_move == 4) { my_move = 1; }
		}

		total_score += my_move;
		total_score += (instruction - 1) * 3;
		
	}
	input.close();

	return total_score;
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

