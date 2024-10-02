#include <iostream>
#include <cstring>
#define SEG_LEN 8
using namespace std;

void invert(string &a) {
    for(int i=0; i<SEG_LEN; i++) {
        a[i] = a[i] == '1' ? '0' : '1';
    }
}
char add(char A, char B, char &carry) {
    if(carry == '1') {
        if(A=='1' && B=='1') {
            carry = '1';
            return '1';
        } else if(A=='0' && B=='0') {
            carry = '0';
            return '1';
        } else if(A!=B) {
            carry = '1';
            return '0';
        }
    } else {
        if(A=='1' && B=='1') {
            carry = '1';
            return '0';
        } else if(A=='0' && B=='0') {
            carry = '0';
            return '0';
        } else {
            carry = '0';
            return '1';
        }
    }
}
void addComplement(string &result, char carry, int n) {
    for(int i=n-1; i>=0; i--) {
        result[i] = add(result[i], '0', carry);
    }
}
void checksum(string data) {
    int n = SEG_LEN;
    int m = data.length() / SEG_LEN;
    string result = data.substr(0, SEG_LEN);
    char carry = '0';

    for(int i=1; i<=m-1; i++) {
        string s = data.substr(i * SEG_LEN, SEG_LEN);
        for(int j=n-1; j>=0; j--) {
            result[j] = add(result[j], s[j], carry);
            if(j==0 && carry=='1') {
                addComplement(result, carry, n);
            }
        }
        carry = '0';
    }
    invert(result);
    cout << data << endl;
    cout << result << endl;
    
    data += result;
    cout << data;
}


int main() {
    string data;
    cin >> data;
    checksum(data);
    return 0;
}