#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "linRegression.h"

int main(int argc, char* argv[])
{
  //input data
  float x[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  float y[] = {3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};

  //hyperparams
  /*float learning_rate = 0.0001;
  int num_iterations = 1000;*/

  //reading in input from command line
  float learning_rate = atof(argv[1]);
  int num_iterations = atoi(argv[2]);
  printf("\nlearning_rate :: %f num_epochs :: %d\n\n", learning_rate, num_iterations);

  //initializing parameters
  srand(time(NULL));
  float w = rand() % 2;
  float b = 0;
  printf("Inital Value Of w %f \n", w);
  printf("Initial Value Of b %f \n", b);

  float *cost = regression(x, y, 10, learning_rate, num_iterations, &w, &b);

  printf("Final Value Of w %f \n", w);
  printf("Final Value Of b %f \n \n", b);

  //predicting values
  float x_predict = atof(argv[3]);
  printf("Predicted Value For %f is %f \n", x_predict, predict(x_predict, w, b));

  //printing cost values over iterations
  /*int count;
  for (count = 0; count < num_iterations; count++)
  {
    printf("Cost %d %f \n", count, cost[count]);
  }*/
  printf("Final Cost: %f\n", cost[num_iterations]);
  exit(EXIT_SUCCESS);
}
