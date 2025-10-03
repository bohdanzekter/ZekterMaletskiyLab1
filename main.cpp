#include "Dominoes.h"
#include <random>

int main()
{
	Dominoes dom;

	int size = dom.dealDominoes();
	dom.show_matrix();

	return 0;
}