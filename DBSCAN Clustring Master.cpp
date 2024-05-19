#include <iostream>
#include <exception>

#include "CSV.h"
#include "DBScanExample.h"
#include "Silhouette.h"


using namespace std;

int main()
{
	try {
		auto read_csv = CSV::read("Resources/editedForce.csv");
		auto allData = read_csv.data();

		auto& data = allData;
		//auto data = std::vector<std::vector<double>>(allData.begin(), allData.begin() +  3000/* max 12203 */);

		std::cout << "~--~--~--~" << std::endl;
		std::cout << "| DBScan |" << std::endl;
		std::cout << "~--~--~--~" << std::endl;
		DBScan::DBScanExample::run1(data, 1, 5 , Distance::Euclidean);
		std::cout << "-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-" << std::endl;
		DBScan::DBScanExample::run2(data, { 2, 10 }, { 0.1, 2 }, 0.5 , Distance::Euclidean);
		std::cout << "-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-__-" << std::endl;

	}
	catch (std::exception e) {
		std::cout << e.what();
	}

	return 0;
}

