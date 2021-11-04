#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**  
 * @file one_dot_two_dash_two.c
 * @auther Scott Garner
 * @date Nov 2 2021
 * @brief Solution to Introduction to Algorithms Excercise 1.2-2
 * 
 * A solution to excercise 1.2-2 in Introduction to Algorithms, 3rd Edition.
 * Solution finds the root of a polynomial via Newtons method.
 */


/**
 * @brief Newtons Method solver for root of function
 * 
 * @param f         \f$ f(x) \f$
 * @param fprime    \f$ f'(x) \f$
 * @param guess     Initial guess for \f$x_0\f$.  Updated to root of function on return
 * @param tol       Convergence tolerance
 * @return success  Returns \f$x_n\f$ cast to an integer.  If solution is found this is 0, otherwise nonzero
 *
 * 
 */
int newtons_method(double (*f)(double),double (*fprime)(double),double * guess,double tol)
{
    int _num_iter = 0;
    int _max_iter = 100;

    double error;
    error = f(*guess);

    fprintf(stderr,"iter:\t%d\tx:\t%f\tf(x):\t%f\n",_num_iter,*guess,f(*guess));

    while (fabs(error)>fabs(tol) & _num_iter++ < _max_iter)
    {
       *guess = *guess - f(*guess)/fprime(*guess); 
       error = f(*guess);
       fprintf(stderr,"iter:\t%d\tx:\t%f\tf(x):\t%f\n",_num_iter,*guess,f(*guess));
    }
    return (int)(*guess);
}

/**
 * @brief Function to look for roots of
 *
 * Excercise 1.2-2 asks at what length of input N an algorithm which runs in 64*N*log_2(N)
 * faster than an 8*N*N algorithm.
 *
 * We'll solve this by solving the equation 
 *
 * \f$  8*N*N - 64*N*log_2(N) = 0 \f$
 *
 * \f$  N(8*N - 64*log_2(N)) = 0 \f$
 *
 * Solving the second equation is fine, since the trivial solution of $N=0$ can be ignored
 *
 * 
 * Change of log base to natural log in the standard math library is
 * \f$ log_b(x)= \frac{log_a(x)}{log_a(b)} \f$
 */
double g(double x)
{
    return (8. * x - 64. * (log(x)/log(2.)));
}

/**
 * @brief Derivative of \f$ g(x) \f$
 * 
 *
 *
 *
 */
double gprime(double x)
{
    return 8 - (64. / log(2.)) / x;
}

int main(int argc, char ** argv)
{
    double root = 100;
    int info;
    info = newtons_method(&g,&gprime,&root,0.00001);
    fprintf(stdout, "Calculated function root:\t%f\n",root);
    fprintf(stdout, "Known root:\t%f\n", 43.5593);
    return 0;
}
