#include <iostream>
#include <cstring>
using namespace std;

string XOR(string num1, string num2) {
    string result = "";
    for(int i=0; i<num1.length(); i++) {
        result += num1[i] == num2[i] ? '0' : '1';
    }
    return result;
}
int find(string text, char ch) {
    for(int i=0; i<text.length(); i++) {
        if(text[i] == ch) {
            return i;
        }
    }
    return -1; // NO ERROR
}

int main() {
    string data, gox;
    cin >> data >> gox;
    string temp = data.substr(0, gox.length());
    int i = gox.length()-1;

    while(i < data.length()) {
        temp = temp[0] == '1'
            ? XOR(temp, gox)
            : temp.substr(1, temp.length()) + data[++i];
    }
    if(find(temp, '1') == -1) {
        cout << "No error !" << endl;
        cout << data.substr(0, data.length() - (gox.length() - 1));
    } else {
        cout << "Error";
    }
    return 0;
}