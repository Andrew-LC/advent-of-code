#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

// get the input data
vector<string> read(string filename) {
    ifstream file{filename};
    string line;
    vector<string> data;

    if (file.is_open()) {
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    } else {
        cerr << "Unable to open the file: " << filename << endl;
    }

    return data;
}

static const int RED_CUBES = 12;
static const int BLUE_CUBES = 14;
static const int GREEN_CUBES = 13;

void part1(const vector<string>& data){
  for(const string& line: data) {
    stringstream ss(line);
    string token;

    while(getline(ss, token, ';')){
      stringstream sub(token);
      cout << token;

      while(sub >> token){
	int count;
	string color;

	sub >> count >> color;
	cout << count << ' ' << color << " | ";
      }
      cout << endl;
    }
  }
}

int main() {
  auto data = read("./data/day02-input.txt");
  part1(data);
}
