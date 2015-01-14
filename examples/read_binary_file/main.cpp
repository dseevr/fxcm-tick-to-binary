#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/algorithm/string.hpp>

using namespace std;

const int RECORD_SIZE = 16;

int main(int argc, char* argv[]) {
	if(2 != argc) {
		cerr << "Usage: " << argv[0] << " input_file.bin" << endl;
		exit(1);
	}

	ifstream input(argv[1], ios::in | ios::binary);
	if(!input.is_open()) {
		cerr << "Failed to open " << argv[1] << endl;
	}

	input.seekg(0, input.end);
	unsigned long size = static_cast<unsigned long>(input.tellg());
	input.seekg(0);

	char *buffer = new char[size];

	input.read(buffer, static_cast<long>(size));
	if (!input) {
		cout << "failed to read input file" << endl;
		exit(1);
	}

	string line;
	time_t *time;
	float *bid, *ask;
	struct tm *tm;
	char timebuf[80];

	for(unsigned long offset = 0; offset <= (size - RECORD_SIZE); offset += RECORD_SIZE) {
		time = reinterpret_cast<time_t *>(buffer + offset);
		bid  = reinterpret_cast<float *>(buffer + offset + 8);
		ask  = reinterpret_cast<float *>(buffer + offset + 12);

		tm = localtime(time);
		strftime(timebuf, 80, "%Y-%m-%d %H:%M:%S", tm);

		cout << "Time: " << timebuf << endl;
		cout << "Bid: " << *bid << endl;
		cout << "Ask: " << *ask << endl;
	}

	delete[] buffer;
}
