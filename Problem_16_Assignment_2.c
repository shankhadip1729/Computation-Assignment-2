#include <stdio.h>
#include <math.h>

// Function to calculate the exact solution
double exact_solution(double t) {
    return pow(t + 1, 2) - 0.5 * exp(t);
}

int main() {
    double t0 = 0; // Initial time
    double y0 = 0.5; // Initial value of y
    double h = 0.2; // Step size
    double t = t0; // Current time
    double y = y0; // Current value of y
    double error_bound; // Upper bound for the error
    double error; // Error
    int steps = 0; // Number of steps

    printf("Step\t\tEuler's Method\t\tExact Solution\t\tError\t\tError Bound\n");

    while (t <= 2) {
        double y_euler = y + h * (y - pow(t, 2) + 1); // Euler's method

        // Calculate the exact solution and error
        double y_exact = exact_solution(t);
        error = fabs(y_euler - y_exact);

        // Calculate the error bound using the derived formula
        error_bound = 0.2 * fabs(y - y_exact + h * (y - pow(t + h, 2) + 1));

        printf("%d\t\t%.6f\t\t%.6f\t\t%.6f\t\t%.6f\n", steps, y_euler, y_exact, error, error_bound);

        // Update values for the next iteration
        t += h;
        y = y_euler;
        steps++;
    }

    return 0;
}
