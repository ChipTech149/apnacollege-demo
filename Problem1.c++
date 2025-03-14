#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to traverse matrix in spiral order from bottom-right to top-left
void spiralTraverse(vector<vector<int>>& mat, int M, int N) {
    vector<int> spiralOrder;
    vector<int> primes;
    int primeSum = 0;
    
    int top = 0, bottom = M - 1, left = 0, right = N - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse from right to left (bottom row)
        for (int i = right; i >= left; --i) {
            spiralOrder.push_back(mat[bottom][i]);
        }
        bottom--;

        // Traverse from bottom to top (left column)
        for (int i = bottom; i >= top; --i) {
            spiralOrder.push_back(mat[i][left]);
        }
        left++;

        // Traverse from left to right (top row)
        if (top <= bottom) {
            for (int i = left; i <= right; ++i) {
                spiralOrder.push_back(mat[top][i]);
            }
            top++;
        }

        // Traverse from top to bottom (right column)
        if (left <= right) {
            for (int i = top; i <= bottom; ++i) {
                spiralOrder.push_back(mat[i][right]);
            }
            right--;
        }
    }

    // Extract prime numbers and compute their sum
    for (int num : spiralOrder) {
        if (isPrime(num)) {
            primes.push_back(num);
            primeSum += num;
        }
    }

    // Print the first output (Spiral Order)
    for (int num : spiralOrder) cout << num << " ";
    cout << endl;

    // Print the second output (Prime numbers in order)
    if (primes.empty()) cout << "0";
    else for (int num : primes) cout << num << " ";
    cout << endl;

    // Print the third output (Sum of prime numbers)
    cout << primeSum << endl;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> mat(M, vector<int>(N));
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }
    }
    
    spiralTraverse(mat, M, N);
    return 0;
}
