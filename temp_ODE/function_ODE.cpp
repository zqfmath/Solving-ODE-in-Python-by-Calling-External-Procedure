#include <cmath>
#include"../Source_Codes/vec_ODE.h"
vec<double> fun(double t, vec<double> &x){
vec<double> f_value(3);
f_value[0]=10*(x[1]-x[0]);
f_value[1]=x[0]*(28-x[2])-x[1];
f_value[2]=x[0]*x[1]-8*x[2]/3;
 return f_value;
}