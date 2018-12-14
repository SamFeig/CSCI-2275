//
// Created by Sam Feig on 12/9/18.
//

#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <iterator>
#include <exception>
#include <sstream>
#include <iostream>

using namespace std;

struct TransformUtils {
	static vector<unsigned char> transformStringToBytes(const string &data) {
		short byte_size = 8;
		const char* buffer_ptr = data.c_str();

		vector<unsigned char> bytes_code;
		for(int pos = 0; (pos / 8) < (data.size() / byte_size); pos += 8) {
			unsigned byte = 0x00;
			for(int b = 0; b < byte_size; ++b) {
				byte <<= 1;
				if (*(buffer_ptr + b + pos) == '1') {
					byte |= 0x01;
				}
			}
			bytes_code.push_back(byte);
		}
		return bytes_code;
	}

	static string transformBytesToString(const unsigned char &byte) {
		bitset<8> byte_str(byte);
		return byte_str.to_string();
	}
};

struct FileUtil {
	static void write(const string& filename, const vector<unsigned char>& data) {
		ofstream output(filename, ios::binary);
		if (!output.is_open()) {
			throw runtime_error("Exception: Unable to open file.");
		}

		copy(data.begin(), data.end(), ostream_iterator<unsigned char>(output));
//        for(int i = 0; i < data.size(); i++) {
//            output << data[i];
//        }
		output.close();
	}

	static void writeString(const string& filename, const string data) {
		ofstream output(filename);
		if (!output.is_open()) {
			throw runtime_error("Exception: Unable to open file.");
		}

		copy(data.begin(), data.end(), ostream_iterator<unsigned char>(output));
		output.close();
	}

	static string read(const string& filename, const int max_per_cycle) {
		ifstream input(filename, ios::binary);
		if (!input.is_open()) {
			throw runtime_error("Exception: Unable to open file.");
		}

		vector<unsigned char> container;
		container.reserve(max_per_cycle);

		stringstream byte_stream;
		const auto transform_to_string = [&byte_stream](unsigned char byte) {
			byte_stream << TransformUtils::transformBytesToString(byte);
		};

		char* const buffer = new char[max_per_cycle];
		while(!input.eof()) {
			input.read(buffer, max_per_cycle);

			const auto count = input.gcount();
			container.insert(container.begin(), buffer, buffer + count);
			for_each(container.begin(), container.begin() + count, transform_to_string);

			memset(buffer, 0, max_per_cycle);
		}
		delete[] buffer;

		input.close();
		return byte_stream.str();
	}

	static string readString(const string& filename) {
		ifstream input(filename);
		if (!input.is_open())
			throw runtime_error("Exception: Unable to open file.");

		string buffer;
		while(input.good()) {
        	string c;
//        	input >> c;
            getline(input, buffer);

        	if(input.eof()) {
            	break;
        	}
//        	buffer += c;
    	}

		input.close();
		return buffer;
	}

	static streampos getFileSize(const string& filename) {
		ifstream file(filename, ios::binary | ios::ate);
		return file.tellg();
	}
};