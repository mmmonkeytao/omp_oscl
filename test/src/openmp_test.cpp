#include <omp.h>
#include <iostream>
#include <Eigen/Dense>
#include <time.h>

using namespace std;
using namespace Eigen;

int main()
{
  VectorXd v1{30000}, v2{30000};
  v1.setRandom(); v2.setRandom();
  
// #pragma omp for nowait
//   for(uint i = 0; i < 3*10e10; ++i)
//     double a = 1+1.0;

//   time = omp_get_wtime() - time;
//   cout << time << "\n";

//   #pragma omp parallel
//   printf("Number of threads: %d\n", omp_get_num_threads());

#pragma omp parallel
  {
    double time = omp_get_wtime();
#pragma omp for schedule(dynamic)
    for(uint i = 0; i < 4*10e8; ++i){
      double var = v1.transpose() * v2;
      //if(var > 0)
      //  int x = 0;
    }

    time = omp_get_wtime() - time;
  
    printf("%d time spent %f.2\n", omp_get_thread_num(),(float)time);

    printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads()); 
  }
 return 0;
}
