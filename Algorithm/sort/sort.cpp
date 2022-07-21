#include "pch.h"
#include "sort.h"


sort::sort()
{
}


sort::~sort()
{
}


//Ã°ÅÝÅÅÐò£¨ÉýÐò£©
void sort::BubbleSort(std::vector<int> &src) {
	for (int i = 0; i < src.size() - 1; i++) {
		bool guard = false;
		for (int j = 0; j < src.size() - i - 1; j++) {
			if (src[i] > src[j + 1]) {
				int tmp = src[i];
				src[i] = src[j + 1];
				src[j + 1] = tmp;
			}
		}
		if (!guard) {
			break;
		}
	}
}