#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "linRegression.h"

int main(int argc, char* argv[])
{
  //input data
  float x[10] = {1,2,3,4,5,6,7,8,9,10};
	float y[10] = {2,4,6,9,15,12,15,17,20,30};

  //hyperparams
  float learning_rate = 0.01;
  int num_iterations = 100;

  //initializing parameters
  srand(time(NULL));
  float w = rand() % 2;
  float b = 0;
  printf("Inital Value Of w %f \n", w);
	printf("Initial Value Of b %f \n", b);

  float *cost = regression(x, y, learning_rate, num_iterations, &w, &b);

  printf("Final Value Of w %f \n", w);
	printf("Final Value Of b %f \n \n", b);

  //predicting values
  printf("Predicted Value For 10 is %f \n", predict(10,&w,&b));

  //printing cost values over iterations
  int count;
  for (count = 0; count < num_iterations; count++)
  {
    printf("Cost %d %f \n", count, cost[count]);
  }
  exit(EXIT_SUCCESS);
}
