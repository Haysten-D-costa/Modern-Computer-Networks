#include <iostream>
#define MAX 20
using namespace std;

void XOR(int num1[MAX], int num2[MAX], int result[MAX], int n) {
    for (int i=0; i<n; i++) {
        result[i] = (num1[i] == num2[i]) ? 0 : 1;
    }
}
    
void binaryDivision(int dividend[MAX], int divisor[MAX], int m, int n) {
    string quotient = "";
    int end = n;

    int zero[MAX] = {0}; 
    int result[MAX] = {0};
    
    for(int i=0; i<n; i++) { // storing 1st 'n' bits to be XORed in result... 
        result[i] = dividend[i];
    }
    for(int i=0; i<m-n+1; i++)  // runs for m(bits in dividend) - n(bits in divisor) + 1...
    {
        int firstDigit = result[0]; // capture 1st digit in result...
        if(firstDigit == 1) {
            quotient.push_back('1');
            XOR(result, divisor, result, n); // will XOR 'result' with 'divisor' and store back to result...
            int nextFromDividend = dividend[end++]; // get bit to be brought down from dividend...

            for(int i=0; i<n-1; ++i) { // discard 1st digit of XORed result and re-arrange...
                result[i] = result[i + 1];
            }
            result[n-1] = nextFromDividend; // append(bring down) next bit form dividend...
        }
        else {
            quotient.push_back('0');
            XOR(result, zero, result, n); // XOR with '0' if 1st bit is 0
            int nextFromDividend = dividend[end++];

            for(int i=0; i<n-1; ++i) {
                result[i] = result[i + 1];
            }
            result[n-1] = nextFromDividend;
        }
    }
    cout << "\n-> Quotient  : " << quotient << endl;
    cout << "-> Remainder : ";
    for(int i=0; i<n-1; i++) {
        cout << result[i];
    }
}

int main() {
    int m, n;
    int result[MAX];
    int divisor[MAX];
    int dividend[MAX];
    cout << "Enter no. of bits in dividend : "; cin >> m;
    cout << "Enter no. of bits in divisor  : "; cin >> n;
    cout << "Enter dividend : ";
    for(int i=0; i<m; i++) { 
        cin >> dividend[i]; 
    }
    cout << "Enter divisor  : ";
    for(int i=0; i<n; i++) {
        cin >> divisor[i];
    }
    binaryDivision(dividend, divisor, m, n);  
    return 0;
}