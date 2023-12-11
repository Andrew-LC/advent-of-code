#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// get the input data
vector<string> read(string filename) {
  ifstream file{filename};
  string line;
  vector<string> data;

  if (file.is_open()) { 
    while(getline(file, line)) {
      data.push_back(line);
    }
    file.close();
  } else {
    cerr << "Unable to open the file: " << filename << endl;
  }

  return data;
}

// check if a char is a number or not
bool check_if_num(char value){
  return value >= '0' && value <= '9';
}

void part1(const vector<string>& data) {
  int sum = 0;
  int firstDigit = 0;
  int lastDigit = 0;
  int result = 0;
  for(const string& line : data){
    if(!line.empty()){
      // first digit
      for(char v: line){
	if(check_if_num(v)) {
	  firstDigit = v - '0';
	  break;
	}
      }

      for(int i = line.size() - 1; i >= 0; --i){
	if(check_if_num(line[i])){
	  lastDigit = line[i] - '0';
	  break;
	} else {
	  lastDigit = firstDigit;
	}
      }

      result = firstDigit * 10 + lastDigit;
      sum += result;
    }
  }

  cout << "[Part1] Sum of calibration values: " << sum << endl;
}


void part2(const std::vector<std::string>& data) {
    std::map<std::string, int> numbers = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };

    int sum = 0; // Initialize sum outside the loop
    int firstDigit = 0;
    int lastDigit = 0;

    for(const std::string& line : data) {
        if(!line.empty()) {
            int result = 0; // Initialize result for each line
            std::string temp; // Initialize temp inside the loop

            for(char v : line) {
                if(check_if_num(v) == true) {
                    firstDigit = v - '0';
		    cout << v << endl;
                    break;
                } else {
                    if(numbers[temp] != 0){
                        firstDigit = numbers[temp];
                        temp = ""; // Clear temp after finding the first digit
                        break;
                    } 
                    temp += v;
                }
            }

	    for(int i = line.size() - 1; i >= 0; --i) {
	      if(check_if_num(line[i])){
		lastDigit = line[i] - '0';
		break;
	      } else {
		string temp_num = temp;
		std::reverse(temp_num.begin(), temp_num.end());
		if(numbers[temp_num] != 0){
		  lastDigit = numbers[temp_num];
		  temp = ""; 
		  break;
		}
		temp += line[i];
	      }
	    }

            result = firstDigit * 10 + lastDigit;
	    cout << result << endl;
            sum += result;
        }
    }

    cout << "[Part2] Sum of calibration values: " << sum << std::endl;
}


int main() {
  auto data = read("./data/day01-input.txt");
  part2(data);

  return 0;
}
