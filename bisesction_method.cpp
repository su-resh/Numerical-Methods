#include <stdio.h>
#include <math.h>

#define e 0.0001

float funct(float x) {
    return x * x - 4 * x - 10;
}

int main() {
    float x1, x2, x0, f1, f2, f0;
    int ite = 0;
    
    printf("Enter the first initial guess: ");
    scanf("%f", &x1);
    printf("Enter the second guess: ");
    scanf("%f", &x2);
    
    f1 = funct(x1);
    f2 = funct(x2);
    
    printf("Iteration\t x1\t\t x2\t\t x0\t\t error\n");
    printf("---------------------------------------------------\n");
    
    if (f1 * f2 < 0) {
        do {
            ite += 1;
            x0 = (x1 + x2) / 2;
            f0 = funct(x0);
            
            printf("%d\t\t%.4f\t\t%.4f\t\t", ite, x1, x2);
            
            if (f1 * f0 < 0) {
                x2 = x0;
            } else {
                x1 = x0;
                f1 = f0;
            }
            
            printf("%.4f\t\t%.4f\n", x0, fabs(x2 - x1));
        } while (fabs(x2 - x1) > e);
        
        printf("------------------------------------------------------\n");
        printf("Hence the root of the given equation is %.4f\n", x0);
    } else {
        printf("Couldn't be processed. Please enter the proper bracketing values.\n");
    }
    
    return 0;
}
