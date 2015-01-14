#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char* argv[]) {
	if(3 != argc) {
		cerr << "Usage: " << argv[0] << " input_file.csv output_file.bin" << endl;
		exit(1);
	}

	ifstream input(argv[1]);
	if(!input.is_open()) {
		cerr << "Failed to open " << argv[1] << endl;
	}

	ofstream output(argv[2], ios::out | ios::binary);
	if(!output.is_open()) {
		cerr << "Failed to open " << argv[2] << endl;
	}

	string line;
	vector<string> parts;
	struct tm tm;
	time_t time;
	float bid, ask;

	while(getline(input, line)) {
		if(0 == line.size()) {
			continue;
		}

		boost::split(parts, line, boost::is_any_of(","));

		if(3 != parts.size()) {
			cerr << "Line \"" << line << "\" must be in tick,bid,ask format" << endl;
			exit(1);
		}

		istringstream ss(parts[0]);
		ss >> get_time(&tm, "%m/%d/%Y %H:%M:%S");

		time = mktime(&tm);
		bid = stof(parts[1], nullptr);
		ask = stof(parts[2], nullptr);

		output.write(reinterpret_cast<char *>(&time), sizeof(time));
		output.write(reinterpret_cast<char *>(&bid), sizeof(bid));
		output.write(reinterpret_cast<char *>(&ask), sizeof(ask));
	}
}
