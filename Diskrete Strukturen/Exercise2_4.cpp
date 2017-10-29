#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int getCardinality(int);

int main() {
	
	getCardinality(4);

	return 0;
}

int getCardinality(int level) {
	int cardinality;
	std::unordered_set<std::string> AX;

	AX.insert("a");

	if (level == 0) {

		cardinality = 1;
	}

	else {
		for (int j = 1; j <= level; j++) {
			std::unordered_set<std::string> AXTemp;

			for (auto k = AX.begin(); k != AX.end(); ++k) {

				AXTemp.insert((*k));
				std::cout << (*k) << std::endl;
			}

			for (auto k = AX.begin(); k != AX.end(); ++k) {

				AXTemp.insert("("+(*k)+")");
				std::cout << (*k) << std::endl;
			}

			for (auto k = AX.begin(); k != AX.end(); ++k) {
				for (auto l = AX.begin(); l != AX.end(); ++l) {
					AXTemp.insert("(" + (*k) + "," + (*l) + ")");
					std::cout << (*k) << std::endl;
				}
			}

			AX = AXTemp;
		}


	}

	cardinality = AX.size();
	
	std::cout << "The cardinality of A" << level << " is " << cardinality << std::endl;
	std::cout << "The elements of AX are " << std::endl;

	for (auto element = AX.begin(); element != AX.end(); ++element)
		std::cout << " " << *element;
	std::cout << std::endl;

	return 0;
}