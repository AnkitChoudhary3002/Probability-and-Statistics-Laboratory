//WAP to generate n random sample of exponential distribution of scale and compute mean and variance check its accuracy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i, j, run;
    float a, b, Error_Mean, Error_Variance;
    float sum_mean = 0, sum_variance = 0;
    cout << "Enter sample size: ";
    cin >> n;
    cout << "Enter the number of times loop will run:";
    cin >> run;
    float transform_expo[n], lambda;
    cout << "Enter the scale value of lambda:";
    cin >> lambda;
    for(i = 0; i < run; i++){
        long long x = 254 + i, p = 110355, q = 1245, r = 214757;
        float random_num[n];
    
        //Generate random numbers
        for (j = 0; j < n; j++) {
            x = (p * x + q) % r;
            random_num[j] = (x + 1.0) / (r + 1.0); // Uniform (0,1)
            transform_expo[j] = (- lambda)* log(1 - (random_num[j]));
        }
        float sum = 0;
        for (j = 0; j < n; j++) {
            sum += transform_expo[j];
        }
        float mean = sum / n;
        sum_mean += mean;

        float sq_sum = 0;
        for (j = 0; j < n; j++) {
            sq_sum += (transform_expo[j] - mean) * (transform_expo[j] - mean);
        }
        float variance = sq_sum / (n - 1);
        sum_variance += variance;
    }

    float average_Smean = sum_mean / run;
    float average_Svariance = sum_variance / run;

    cout << "\nAverage Sample Mean: " << average_Smean << endl;
    cout << "Population Mean: " << lambda << endl;
    
    Error_Mean = (average_Smean - (lambda));
    if(Error_Mean<0){
        Error_Mean=-Error_Mean;
        }
    cout << "Error in Mean: " << Error_Mean << endl;
    cout << endl;
    cout << "Average Sample Variance: " << average_Svariance << endl;
    cout << "Population Variance: " << (lambda * lambda) << endl;

    Error_Variance = (average_Svariance - (lambda * lambda));
    if(Error_Variance<0){
        Error_Variance=-Error_Variance;
    }
    cout << "Error in Variance: " << Error_Variance << endl;

    return 0;
}