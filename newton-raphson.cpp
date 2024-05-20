#include <stdio.h>
#include <math.h>

#define e 0.00001

float x0, x1, F0, F1, error;
int ite = 0;

// Function definition for the given equation
float Funct(float x) {
    return x - 1.5 * sin(x) - 2.53;
}

// Function definition for the derivative of the given equation
float funct_derive(float x) {
    return 1 - 1.5 * cos(x);
}

int main() {
    printf("Enter the initial value\n");
    scanf("%f", &x0);
    printf("iteration\t x0\t\t x1\t\t F0\t\t error\n");
    
    do {
        F0 = Funct(x0);        // Calculate the function value at x0
        F1 = funct_derive(x0); // Calculate the derivative at x0
        x1 = x0 - (F0 / F1);   // Update x1 using Newton-Raphson formula
        error = fabs((x1 - x0) / x1); // Calculate the relative error
        
        // Print the current iteration results
        printf("%d\t\t %f\t %f\t %f\t %f\n", ++ite, x0, x1, F0, error);
        
        x0 = x1; // Update x0 for the next iteration
    } while (error > e);
    
    printf("\nThe root of the given equation is %f\n", x0);
    return 0;
}
