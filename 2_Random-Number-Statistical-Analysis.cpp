//to generate n random numbers in interval (a,b), sort them, find median and mode, and split sorted array at index z

#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    int x = 10, p = 450, q = 560, r = 4350, z = 0;
    float a, b;
    float random_num[1000], temp, raw_val;
    
    cout << "Enter the number of random integers to generate: ";
    cin >> n;
    
    cout << "Enter the interval (a b): ";
    cin >> a >> b;
    
    cout.precision(3);
    cout << fixed; 
    
    cout << "\nGenerated random numbers:\n";
    for (i = 0; i < n; i++) {
        x = (p * x + q) % r;
        raw_val = a + (b - a) * (x / (r - 1.0));
  
        random_num[i] = (int)(raw_val * 1000 + 0.5) / 1000.0;
        // ----------------------------------------------

        cout << random_num[i] << ",";
    }
    cout << "\b.\n";
    
    // Sort entire array once (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (random_num[j] > random_num[j + 1]) {
                temp = random_num[j];
                random_num[j] = random_num[j + 1];
                random_num[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted numbers:\n";
    for (i = 0; i < n; i++) {
        cout << random_num[i] << ",";
    }
    cout << "\b.\n" ;

    // Median
    cout << "Median: ";
    if (n % 2 == 0){
        cout << (random_num[n/2 - 1] + random_num[n/2]) / 2.0 << endl;
    }
    else{
        cout << random_num[n/2] << endl;
    }

    // Mode logic (Linear scan since array is sorted & rounded)
    float mode = random_num[0], curr = random_num[0];
    int maxCount = 0, count = 0;

    for(i = 0; i < n; i++) {
        if (random_num[i] == curr) {
            count++;
        } else {
            curr = random_num[i];
            count = 1;
        }
        if (count > maxCount) {
            maxCount = count;
            mode = curr;
        }
    }
    cout << "Mode: " << mode << endl;
    
    cout << "\n\nEnter split index z: ";
    cin >> z;

    cout << "\nSorted numbers upto number 1 - " << z << ":\n";
    for (i = 0; i < z; i++) {
        cout << random_num[i] << ",";
    }
    cout << "\b.\n" ;

    cout << "\nSorted numbers in decreasing order upto number " << z << " - " << n << ":\n";
    // Optimization: Just print the already sorted array backwards
    for (i = n - 1; i >= z; i--) {
        cout << random_num[i] << ",";
    }
    cout << "\b.\n" ;

    return 0;
}