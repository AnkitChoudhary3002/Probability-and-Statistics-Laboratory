// Program to generate 2n random samples using. 
// Polar (Marsaglia) method and compute mean and variance

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, run, i, j;
    float Error_Mean, Error_Variance;
    float sum_mean = 0, sum_variance = 0;

    cout << "Enter sample size (n): ";
    cin >> n;

    cout << "Enter the number of times loop will run: ";
    cin >> run;

    // Limits for uniform distribution
    float a = -1.0, b = 1.0;

    for (i = 0; i < run; i++) {

        long long x = 250 + i, p = 110360, q = 1260, r = 214750;
        float Z[2 * n];
        int count = 0;

        // Generate 2n normal random variables using polar method
        while (count < 2 * n) {

            x = (p * x + q) % r;
            float U1 = a + (b - a) * (x / float(r - 1.0));

            x = (p * x + q) % r;
            float U2 = a + (b - a) * (x / float(r - 1.0));

            float S = U1 * U1 + U2 * U2;
            if (S > 0 && S < 1) {

                float factor = sqrt((-2) * log(S) / S);

                // Explicit Z1 and Z2
                float Z1 = U1 * factor;
                float Z2 = U2 * factor;

                Z[count++] = Z1;
                if (count < 2 * n)
                    Z[count++] = Z2;
            }
        }

        // Mean calculation
        float sum = 0;
        for (j = 0; j < 2 * n; j++)
            sum += Z[j];

        float mean = sum / (2 * n);
        sum_mean += mean;

        // Variance calculation
        float sq_sum = 0;
        for (j = 0; j < 2 * n; j++)
            sq_sum += (Z[j] - mean) * (Z[j] - mean);

        float variance = sq_sum / (2 * n - 1);
        sum_variance += variance;
    }

    float avg_mean = sum_mean / run;
    float avg_variance = sum_variance / run;

    cout << "\nAverage Sample Mean: " << avg_mean << endl;
    cout << "Population Mean: " << 0 << endl;

    Error_Mean = avg_mean;
    if (Error_Mean < 0)
        Error_Mean = -Error_Mean;

    cout << "Error in Mean: " << Error_Mean << endl;

    cout << "\nAverage Sample Variance: " << avg_variance << endl;
    cout << "Population Variance: " << 1  << endl;

    Error_Variance = avg_variance - 1;
    if (Error_Variance < 0)
        Error_Variance = -Error_Variance;

    cout << "Error in Variance: " << Error_Variance << endl;

    return 0;
}