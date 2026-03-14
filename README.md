# Probability and Statistics Laboratory

C++ implementations of core probability & statistics building blocks written from scratch (no STL random, no external deps). The focus is on understanding the math behind pseudo‑random number generation, sampling, and descriptive statistics.

## Contents
- **1_lcg_random_mean_variance.cpp** – Linear Congruential Generator (LCG) for uniform samples; computes mean & variance.
- **2_Random-Number-Statistical-Analysis.cpp** – Extended descriptive stats: mean, median, mode, sorting, rounding.
- **MonteCarlo_MeanVariance_LCG.cpp** – Monte Carlo estimation of mean/variance using the LCG stream.
- **MarsagliaPolar_NormalSimulation.cpp** – Normal (Gaussian) sampling via Marsaglia polar method with error analysis.
- **box_muller_stats.cpp** *(stub)* – Placeholder for a Box–Muller normal sampler.
- **weibull_distibution.cpp** *(stub)* – Placeholder for a Weibull distribution sampler.

## Quick start
Clone and build any file you want to run:
```bash
g++ -std=c++17 -O2 1_lcg_random_mean_variance.cpp -o lcg
./lcg

g++ -std=c++17 -O2 MarsagliaPolar_NormalSimulation.cpp -o normal
./normal
```

> Uses only the standard headers `iostream` and `cmath`, plus basic arrays/loops.

## What you can explore
- **Uniform RNG (LCG):** experiment with different multipliers, moduli, and seeds to see period and uniformity effects.
- **Descriptive statistics:** compute mean, median, mode; observe sensitivity to sample size and rounding.
- **Normal sampling:** compare the Marsaglia polar output with theoretical μ/σ; track error as sample count grows.
- **Monte Carlo intuition:** run repeated simulations to see convergence of empirical mean/variance.

## Suggested experiments
- Vary LCG parameters and plot histograms of outputs.
- Increase sample sizes in `MarsagliaPolar_NormalSimulation.cpp` and log how the error term shrinks.
- Fill in the stubs:
  - Implement **Box–Muller** in `box_muller_stats.cpp` and compare performance vs. Marsaglia polar.
  - Implement **Weibull** sampling (inverse CDF or acceptance–rejection) in `weibull_distibution.cpp`.

## Repository goals
- Educational, step-by-step implementations.
- Readable code with minimal dependencies.
- A playground for Monte Carlo methods and distribution sampling.

## Contributing
Feel free to open issues or PRs with:
- Additional distributions (exponential, gamma, Poisson).
- Visualizations or benchmarks comparing methods.
- Tests or CI scripts to validate RNG quality and statistical outputs.

---
