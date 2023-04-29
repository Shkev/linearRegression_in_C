#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linRegression.h"

/**
* Update weight and bias using gradient descent.
* Uses all of data to compute gradient
* Returns loss
*/
float batch_gradient_descent(float x[], float y[], int num_data, float learning_rate, float* w, float* b)
{
  float db = 0.0; // derivative of cost func with respect to bias
  float dw = 0.0; // derivative of cost func with respect to weights
  float loss = 0.0;
	// go through all data points to compute loss
  for (size_t count = 0; count < num_data; count++)
  {
    loss += pow(((*w * x[count] + *b) - y[count]), 2); // equation to find loss/empirical risk
    db += (*w * x[count] + *b) - y[count];
    dw += ((*w * x[count] + *b) - y[count]) * x[count];
  }
	loss /= 2*num_data;
	db /= num_data;
	dw /= num_data;
  // updating weight and bias using gradient descent
  *w = *w - (learning_rate * dw);
  *b = *b - (learning_rate * db);
	
  return loss;
}

/**
* Perform regression on given dataset (x, y) using num_iterations number of iterations.
* Returns the final loss after training is complete.
*/
float* regression(float x[], float y[], int num_data, float learning_rate, int num_iterations, float* w, float* b)
{
  float* loss;
  loss = malloc(sizeof(int) * num_iterations);
  for (size_t count = 0; count < num_iterations; count++)
  {
    loss[count] = batch_gradient_descent(x, y, num_data, learning_rate, w, b);
  }
  return loss;
}

/**
* Predict output for given input x with given weights and biases
*/
float predict(float x, float w, float b)
{
  float y = w * x + b;
  return y;
}
