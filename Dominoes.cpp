#include "Dominoes.h"

Dominoes::Dominoes(int maxNumber)
{
	n = maxNumber + 1;		//to include number 'n' itself
	dominoes.assign(n, std::vector<bool>(n, false));
	table = createRandTile();
	insert(table);
}

void Dominoes::show_matrix()
{
	for (auto it : dominoes)
	{
		for (auto it1 : it)
		{
			std::cout << it1 << " ";
		}
		std::cout << std::endl;
	}
}

void Dominoes::insert(int first, int second)
{
	dominoes[first][second] = true;
	dominoes[second][first] = true;

}
void Dominoes::insert(std::pair<int, int> pair)
{
	dominoes[pair.first][pair.second] = true;
	dominoes[pair.second][pair.first] = true;
}

void Dominoes::erase(int first, int second)
{
	dominoes[first][second] = false;
	dominoes[second][first] = false;
}
void Dominoes::erase(std::pair<int, int> pair)
{
	dominoes[pair.first][pair.second] = false;
	dominoes[pair.second][pair.first] = false;
}

std::pair<int, int> Dominoes::createRandTile()
{
	std::uniform_int_distribution<> dist(0, n - 1);
	int a = dist(gen);
	int b = dist(gen);
	if (a > b) std::swap(a, b);
	return { a, b };
}

std::pair<int, int> Dominoes::operator() () {
	std::pair<int, int> newTile;
	int attempts = 0;
	int multiplier = 1000;							//We need this for eliminating 
	int maxAttempts = multiplier * multiplier;		//problem with unlucky random

	while (attempts < maxAttempts) {
		newTile = createRandTile();
		if (!dominoes[newTile.first][newTile.second] && sharesPart(table, newTile)) {
			if (canAttachBothEnds(newTile)) {
				newTile = chooseSmallestEnd(newTile);
			}
			this->insert(newTile);
			changeTable(newTile);
			return newTile;
		}
		attempts++;
	}
	return { -1, -1 };
}

bool Dominoes::canAttachBothEnds(const std::pair<int, int>& tile) const {
	return (tile.first == table.first || tile.second == table.first) ||
		(tile.first == table.second || tile.second == table.second);
}

std::pair<int, int> Dominoes::chooseSmallestEnd(const std::pair<int, int>& tile) const {
	int end1 = (tile.first == table.first || tile.second == table.first) ? table.first : table.second;
	int end2 = (tile.first == table.second || tile.second == table.second) ? table.second : table.first;
	return (end1 < end2) ? std::make_pair(tile.first, tile.second) : std::make_pair(tile.second, tile.first);
}

int Dominoes::dealDominoes()
{
	int count = 1;
	show_pair(table);
	while (true)
	{
		auto tile = operator()();
		if (tile.first == -1 && tile.second == -1)
			break;
		show_pair(tile);
		count++;
	}
	return count;
}

void Dominoes::show_pair(std::pair<int, int> a)
{
	std::cout << a.first << " " << a.second << std::endl;
}

void Dominoes::reset()
{
	dominoes.assign(n, std::vector<bool>(n, false));
	table = createRandTile();
	insert(table);
}

bool Dominoes::sharesPart(std::pair<int, int> a, std::pair<int, int> b) {
	if (a.first > a.second) std::swap(a.first, a.second);
	if (b.first > b.second) std::swap(b.first, b.second);

	
	return (a.first == b.first) ||
		(a.first == b.second) ||
		(a.second == b.first) ||
		(a.second == b.second);
}

void Dominoes::changeTable(const std::pair<int, int>& a)
{
	if (a.first == table.first)
	{
		table = { table.second, a.second };
	}
	else if (a.first == table.second)
	{
		table = { table.first, a.second };
	}
	else if (a.second == table.first)
	{
		table = { table.second, a.first };
	}
	else if (a.second == table.second)
	{
		table = { table.first, a.first };
	}
}
