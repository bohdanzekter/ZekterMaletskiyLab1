#include "Dominoes.h"
#include <algorithm>
#include <numeric>
#include <map>

int main()
{
	int n, numDeals;

	std::cout << "Enter max number on dominoes( >= 0 ): ";
	while (!(std::cin >> n) || n < 0) {
		std::cout << "Invalid input (number must be greater than or equal to 0), try again: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}

	std::cout << "Enter number of deals( > 0 ): ";
	while (!(std::cin >> numDeals) || numDeals <= 0) {
		std::cout << "Invalid input (number must be greater than 0), try again: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
		
	std::cout << "Max number on dominoes: " << n << "\nAmount of draws: " << numDeals;


	std::vector<int> sizes(numDeals);
	Dominoes dom(n);

	for (int i = 0; i < numDeals; ++i) {
		dom.reset();
		sizes[i] = dom.dealDominoes();
	}

	std::cout << "Draw sizes: ";
	for (auto s : sizes) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	std::sort(sizes.begin(), sizes.end());
	double average = static_cast<double>(std::accumulate(sizes.begin(), sizes.end(), 0)) / numDeals;
	double median;

	if (numDeals % 2 == 0) {
		median = (sizes[numDeals / 2 - 1] + sizes[numDeals / 2]) / 2.0;
	}
	else {
		median = sizes[numDeals / 2];
	}

	std::map<int, int> frequency;
	for (int s : sizes) { frequency[s]++; }

	int mode = sizes[0];
	int maxFreq = 0;

	for (auto& [size, freq] : frequency) {
		if (freq > maxFreq) {
			maxFreq = freq;
			mode = size;
		}
	}

	std::cout << "Average size: " << average << std::endl;
	std::cout << "Median size: " << median << std::endl;
	std::cout << "Mode size: " << mode << std::endl;

	std::cout << "Percentages:" << std::endl;
	for (auto& [size, count] : frequency) 
	{
		double percent = 100.0 * count / numDeals;
		std::cout << size << ": " << percent << "%" << std::endl;
	}

	return 0;
}