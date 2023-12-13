#include <iostream>
#include <vector>
#include <map>

using namespace std;

class StaticHuffman {
private:
    map<char, string> codes;

public:
    StaticHuffman(string data) {
        map<char, int> freqMap;
        for (char c : data)
            freqMap[c]++;
            
        for (auto pair : freqMap) {
            string code = "";
            for (int i = 0; i < pair.second; i++)
                code += '1';
            codes[pair.first] = code;
        }
    }

    string encode(string input) {
        string output = "";
        for (char c : input) {
            output += codes[c];
        }
        return output;
    }

    string decode(string input) {
        string output = "";
        char currentChar = input[0];
        int count = 0;
        for (char c : input) {
            if (c == '1')
                count++;
            else {
                output += string(count, currentChar);
                currentChar = c;
                count = 0;
            }
        }
        return output;
    }
};

int main() {
    string str = "CNTT10110CLCCNNTTT10000CCCCLLLLCCCTTTT11000NTNNN000TNT";
    StaticHuffman huff(str);
    
    string encodedStr = huff.encode(str);
    cout << "Chu?i sau khi nén: " << encodedStr << endl;

    string decodedStr = huff.decode(encodedStr);
    cout << "Chu?i sau khi gi?i nén: " << decodedStr << endl;

    return 0;
}

