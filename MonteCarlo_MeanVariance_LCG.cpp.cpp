#include <iostream>
using namespace std;

int main() {
    int n, i, j, run;
    float a, b, Error_Mean, Error_Variance, Error_Median;
    float sum_mean = 0, sum_median = 0, sum_variance = 0;
    cout << "Enter the number of random integers to generate: ";
    cin >> n;
    cout << "Enter the interval (a b): ";
    cin >> a >> b;
    cout << "Enter the number of times loop will run:";
    cin >> run;
    for(i = 0; i < run; i++){
        long long x = 254 + i, p = 110355, q = 1245, r = 214757;
        float random_num[100];
    
        //Generate random numbers/ 
        for (j = 0; j < n; j++) {
            x = (p * x + q) % r;
            random_num[j] = a + (b - a) * x / (r - 1.0);
        }
        
        float sum = 0;
        for (j = 0; j < n; j++) {
            sum += random_num[j];
        }
        float mean = sum / n;
        sum_mean += mean;

        float sq_sum = 0;
        for (j = 0; j < n; j++) {
            sq_sum += (random_num[j] - mean) * (random_num[j] - mean);
        }
        float variance = sq_sum / (n - 1);
        sum_variance += variance;
    }

    float average_Smean = sum_mean / run;
    float average_Svariance = sum_variance / run;

    cout << "\nAverage Sample Mean: " << average_Smean << endl;
    cout << "Population Mean: " << (a + b) / 2 << endl;
    
    Error_Mean = (average_Smean - ((a + b) / 2));
    if(Error_Mean<0){
        Error_Mean=-Error_Mean;
        }
    cout << "Error in Mean: " << Error_Mean << endl;
    cout << endl;
    cout << "Average Sample Variance: " << average_Svariance << endl;
    cout << "Population Variance: " << ((b - a) * (b - a)) / 12 << endl;

    Error_Variance = (average_Svariance - (((b - a) * (b - a)) / 12));
    if(Error_Variance<0){
        Error_Variance=-Error_Variance;
    }
    cout << "Error in Variance: " << Error_Variance << endl;

    return 0;
}