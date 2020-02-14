#ifndef LINREGRESSION_H_
#define LINREGRESSION_H_

//declaring functions


/*Determines cost and adjusts
*weights and bias.
*The optimizer.
*/
float batch_gradient_descent(float*, float*, int, float, float*, float*);

/*runs linear regression through iterations.
*Determines weights and biases and cost in
*each iteration.
*Returns array with cost values.
*/
float* regression(float*, float*, int, float, int, float*, float*);

/*predicts output given input values*/
float predict(float, float, float);

#endif
