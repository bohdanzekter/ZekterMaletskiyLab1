#include "Dominoes.h"
#include <random>

int main()
{
	int n, numDraws;
	std::cout << "Enter max number on dominoes: ";
	std::cin >> n;
	std::cout << "Enter number of draws: ";
	std::cin >> numDraws;

	std::vector<int> sizes(numDraws);
	Dominoes dom;

	for (int i = 0; i < numDraws; ++i) {
		dom.reset();
		sizes[i] = dom.dealDominoes();
	}

	std::cout << "Draw sizes: ";
	for(auto s: sizes){
		std::cout << s << " ";
	}
	std::cout << std::endl;
	return 0;
}