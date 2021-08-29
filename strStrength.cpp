
#include "strStrength.h"

using namespace std;

int main(int argc, char** argv)
{
	//Checking user input...
	if (argc != 3){
		cout << "You must call this program with two whole ints >= 0." 
			<< endl;
		return 1;
	}
	try {
		if ( stoi(argv[1]) < 0 || stoi(argv[2]) < 0){
			cout << "You must call this program with two whole " 
				<< "ints >= 0." << endl;
			return 1;
		}
	} catch(...){ 
		cerr << "You must enter integers!\n";
	}

	int sn = stoi(argv[1]);
	int maxWeight = stoi(argv[2]);
	int tests{0};

	if (maxWeight < 1000 || sn == 1){
		//auto start = std::chrono::high_resolution_clock::now();
		tests = minTests(maxWeight, sn);
		//auto end = std::chrono::high_resolution_clock::now();
		//auto duration = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
		//cout << duration.count() << endl;
		//cout << "Min test: " << tests << endl;
	} else {
		//auto start2 = std::chrono::high_resolution_clock::now();
		tests = buildTable(maxWeight, sn);
		//auto end2 = std::chrono::high_resolution_clock::now();
		//auto duration2 = std::chrono::duration_cast<std::chrono::microseconds> (end2 - start2);
		//cout << duration2.count() << endl;
		//cout << "Min test: " << tests << endl;
	}
	cout << "Min tests: " << tests << endl;

	return 0;
}

int buildTable(int numf, int m)
{
	//In case user inputs a very large m, shrink it
	//to only the size you need. 
	int m_prime = log2(numf) + 1;
	if (m_prime < m)
		return m_prime;
	
	unique_ptr<int[]> currentRow = make_unique<int[]>(m + 1);
	unique_ptr<int[]> previousRow = make_unique<int[]>(m + 1);

	//initialize rows
	for (int i = 0; i <= m; i++)
		previousRow[i] = 1;

	currentRow[0] = 1;
	
	int tests = 0;
	while(previousRow[m] <= numf){
		for(int i = 0; i < m; i++)
			currentRow[i+1] = previousRow[i] + previousRow[i+1];

		currentRow.swap(previousRow);

		tests++;
	} 	

	return tests;
}

int maxTestableWeight (int tn, int sn)
{
	if (tn == 0 || sn == 0)
		return 0;

	// A little time saving coarsening.
	if (tn == 1 ||  sn == 1)
		return tn;

	return maxTestableWeight(tn-1, sn-1) + maxTestableWeight(tn-1, sn) +1;
}

int minTests (int maxWeight, int sn)
{
	int tn = 0;
	while(maxTestableWeight(tn, sn) < maxWeight)
		tn++;

	return tn;
}
