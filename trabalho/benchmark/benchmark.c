#include <stdio.h>
#include <time.h>

clock_t benchmark_time;

void start_benchmark(){
  benchmark_time = clock();
}

void end_benchmark(){
  benchmark_time = clock() - benchmark_time; 

  double seconds = (double)benchmark_time / CLOCKS_PER_SEC;
  
  printf("Tempo: %f segundos.\n", seconds);
}

