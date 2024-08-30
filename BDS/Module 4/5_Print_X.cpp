#include <iostream>
using namespace std;

void printPattern(int N) {
    int mid = (N / 2) + 1;
    
    for (int i = 1; i <= N; ++i) {
        if (i < mid) {
            // Print leading spaces
            for (int j = 1; j < i; ++j)
            {
                cout << " ";
            }
            // Print '\' and '/'
            cout << "\\";
            for (int j = 1; j <= 2 * (mid - i ); ++j)
            {
                cout << " ";
            }
            cout << "/" << endl;
        } 
        else if (i == mid) 
        {
            // Print leading spaces
            for (int j = 1; j < mid; ++j) {
                cout << " ";
            }
            // Print 'X'
            cout << "X" << endl;
        }
        else
        {
            // Print leading spaces
            for (int j = 1; j <= N - i; ++j) {
                cout << " ";
            }
            // Print '/' and '\'
            cout << "/";
            for (int j = 1; j <= 2 * (i - mid); ++j) {
                cout << " ";
            }
            cout << "\\" << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    printPattern(N);
    
    return 0;
}
