#include <iostream>
#define MAX 20
using namespace std;

void XOR(int num1[MAX], int num2[MAX], int result[MAX], int n) {
    for (int i=0; i<n; i++) {
        result[i] = (num1[i] == num2[i]) ? 0 : 1;
    }
}
    
void CRC_Receiver(int dividend[MAX], int divisor[MAX], int m, int n) {
    string quotient = "";
    int start = 0;
    int end = n;
    
    int zero[MAX] = {0};
    int result[MAX] = {0};

    for(int i=0; i<n; i++) {
        result[i] = dividend[i];
    }
    for(int i=0; i<m-n+1; i++) {
        int firstDigit = result[0];
        if(firstDigit == 1) {
            quotient.push_back('1');
            XOR(result, divisor, result, n);
            int nextFromDividend = dividend[end++];

            for(int i=0; i<n-1; ++i) {
                result[i] = result[i + 1];
            }
            result[n-1] = nextFromDividend;
        }
        else {
            quotient.push_back('0');
            XOR(result, zero, result, n);
            int nextFromDividend = dividend[end++];

            for(int i=0; i<n-1; ++i) {
                result[i] = result[i + 1];
            }
            result[n-1] = nextFromDividend;
        }
    }
    cout << "\nQuotient  : " << quotient << endl;
    cout << "Remainder : ";
    for(int i=0; i<n-1; i++) {
        cout << result[i];
    }
    bool flag = true;
    for(int i=0; i<n-1; i++) {
        if(result[i] == 1) { 
            flag = false;
        }
    }
    if(flag) {
        cout << "\n\nReceived CodeWord doesn't contain error !";
        cout << "\nActual data is : ";
        for(int i=0; i<m-n+1; i++) {
            cout << dividend[i];
        }
    } else { cout << "\nReceived CodeWord contains error !\nRetransmit codeword again !!"; }
}

int main() {
    int m, n;
    int goX[MAX];
    int code_word[MAX] {0};
    cout << "\nEnter no. of bits in received CodeWord : "; cin >> m;
    cout << "Enter no. of bits in g(x) : "; cin >> n;
    cout << "Enter CodeWord : ";
    for(int i=0; i<m; i++) { 
        cin >> code_word[i]; 
    }
    cout << "Enter g(x) : ";
    for(int i=0; i<n; i++) {
        cin >> goX[i];
    }
    CRC_Receiver(code_word, goX, m, n); 
    return 0;
}