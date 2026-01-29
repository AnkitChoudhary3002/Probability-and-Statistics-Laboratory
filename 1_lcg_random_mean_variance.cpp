// To generate 'n' random integers in interval 'a' and 'b' and find their mean and variance.

#include <iostream>
using namespace std;

int main(){
    int n , i, x;
    int  p = 4551, q = 564, r = 43531;
    float a, b;
    cout << "Enter the number of random integers to generate: ";
    cin >> n;
    cout << "Enter the interval (a b): ";
    cin >> a >> b;
    cout << "initial value: ";
    cin >> x;
    x = (p*x + q) % r;
    float sum = 0, sum_sq = 0, mean, variance;
    cout << "Generated random integers: ";
    float random_num[100];
    for(i = 0; i < n; i++){
        x = (p*x + q) % r;
        random_num[i] = a + (b - a) * (x / (r - 1.0));
        // cout << a << " " << b << " " << x << " " << r << endl;
        cout << random_num[i] << ",";
        sum += random_num[i];
    }
    cout << "\b.\n";

    mean = sum / n;
    cout << "Mean: " << mean << endl;

    for(i = 0; i < n; i++){
        sum_sq += (random_num[i] - mean) * (random_num[i] - mean);
    }
    variance = sum_sq / n;
    cout << "Variance: " << variance << endl;

    return 0;
}