#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linRegression.h"

float batch_gradient_descent(float x[], float y[], int num_data, float learning_rate, float* w, float* b)
{
  float db = 0.0; //derivative of cost func with respect to bias
  float dw = 0.0; //derivative of cost func with respect to weights
  float cost = 0.0;
  int count;
  for (count = 0; count < num_data; count++)
  {
    cost += pow((((*w) * x[count] + *b) - y[count]), 2) / (2 * num_data); //equation to find cost
    db += ((*w * x[count] + *b) - y[count]) / num_data;
    dw += ((*w * x[count] + *b) - y[count]) * x[count] / num_data;
  }

  //updating weight and bias
  *w = *w - (learning_rate * dw);
  *b = *b - (learning_rate * db);
  return cost;
}

float* regression(float x[], float y[], int num_data, float learning_rate, int num_iterations, float* w, float* b)
{
  static float* cost;
  cost = malloc(sizeof(int) * num_iterations);
  int count;
  for (count = 0; count < num_iterations; count++)
  {
    cost[count] = batch_gradient_descent(x, y, num_data, learning_rate, w, b);
  }
  return cost;
}

float predict(float x, float w, float b)
{
  float y = w * x + b;
  return y;
}
