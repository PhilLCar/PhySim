#include <stdlib.h>
#include <cmath.h>

typedef vector struct Vector {
  int dim;
  double *vals;
};

typedef matrix struct Matrix {
  int m;
  int n;
  double det;
  double **rows;
  double *row(m);
  double *col(n);
};
