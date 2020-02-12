#ifndef LINREGRESSION_H_
#define LINREGRESSION_H_

//declaring functions


/*Determines cost and adjusts
*weights and bias
*/
float batch_gradient_descent();

/*runs linear regression through iterations.
*Determines weights and biases and cost in
*each iteration.
*Returns array with cost values.
*/
float* regression();

/*predicts output given input values*/
float predict();

#endif
