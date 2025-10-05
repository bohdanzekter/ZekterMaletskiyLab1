#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <random>

class Dominoes
{
	int n = 0;
	std::vector<std::vector<bool>> dominoes;
	std::pair<int, int> table;
	int sharedPart = -1;

	std::mt19937 gen{ std::random_device{}() };
	
public:	

	Dominoes(int maxNumber);

	int dealDominoes();

	void show_pair(std::pair<int, int> a);
	void reset();

private:
	void show_matrix();			//for debbuging

	void insert(int first, int second);
	void insert(std::pair<int, int> pair);
	void erase(int first, int second);
	void erase(std::pair<int, int> pair);

	std::pair<int, int> operator() ();
	std::pair<int, int> createRandTile();

	bool canAttachBothEnds(const std::pair<int, int>& tile) const;
	void changeTable(const std::pair<int, int>& a);

	std::pair<int, int> chooseSmallestEnd(const std::pair<int, int>& tile) const;
	bool sharesPart(std::pair<int, int> a, std::pair<int, int> b);

};