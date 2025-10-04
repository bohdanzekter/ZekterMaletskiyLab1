#include "Dominoes.h"
#include <algorithm>
#include <numeric>
#include <map>

int main()
{
	int n, numDraws;
	std::cout << "Enter max number on dominoes: ";
	std::cin >> n;
	std::cout << "Enter number of draws: ";
	std::cin >> numDraws;

	std::vector<int> sizes(numDraws);
	Dominoes dom(n);

	for (int i = 0; i < numDraws; ++i) {
		dom.reset();
		sizes[i] = dom.dealDominoes();
	}

	std::cout << "Draw sizes: ";
	for (auto s : sizes) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	std::sort(sizes.begin(), sizes.end());
	double average = static_cast<double>(std::accumulate(sizes.begin(), sizes.end(), 0)) / numDraws;
	double median;

	if (numDraws % 2 == 0) {
		median = (sizes[numDraws / 2 - 1] + sizes[numDraws / 2]) / 2.0;
	}
	else {
		median = sizes[numDraws / 2];
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
		double percent = 100.0 * count / numDraws;
		std::cout << size << ": " << percent << "%" << std::endl;
	}

	return 0;
}