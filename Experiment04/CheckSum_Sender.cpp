#include <iostream>
#include <vector>
#define MAX 30
using namespace std;

vector<int> addBinary(const vector<int>& num1, const vector<int>& num2, int size)
{
    int carry = 0;
    int bitA, bitB;
    vector<int> result(size, 0);
    vector<int> one(size, 0);

    for(int i=size-1; i>=0; i--)
    {
        bitA = num1[i];
        bitB = num2[i];
        int sum = bitA + bitB + carry;

        if(sum == 0) {
            result[i] = 0;
        }
        else if(sum == 1) {
            result[i] = 1;
            carry = 0;
        }
        else if(sum == 2) {
            result[i] = 0;
            carry = 1;
        }
        else if(sum == 3) {
            result[i] = 1;
            carry = 1;
        }
    }
    if(carry == 1) {
        for(int i=0; i<size; i++) {
            if(i == size-1) {
                one[i] = 1;
            }
            else { one[i] = 0; }
        }
        result = addBinary(result, one, size);
    }
    return result;
}

int main() {

    int segSize = 8;

    vector<int> seg1 = {1, 0, 1, 1, 0, 0, 1, 1};
    vector<int> seg2 = {1, 0, 1, 0, 1, 0, 1, 1};
    vector<int> seg3 = {0, 1, 0, 1, 1, 0, 1, 0};
    vector<int> seg4 = {1, 1, 0, 1, 0, 1, 0, 1};

    vector<int> result = addBinary(addBinary(seg1, seg2, segSize), addBinary(seg3, seg4, segSize), segSize);

    for(int i=0; i<segSize; i++) {
        if(result[i] == 1) { result[i] = 0; }
        else { result[i] = 1; }
    }
    cout << "Result : ";
    for(int bit : seg1) { cout << bit << " "; }
    for(int bit : seg2) { cout << bit << " "; }
    for(int bit : seg3) { cout << bit << " "; }
    for(int bit : seg4) { cout << bit << " "; }
    for(int bit : result) { cout << bit << " "; }
    return 0;
}
