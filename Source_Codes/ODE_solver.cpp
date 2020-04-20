#include <iostream>
#include <fstream>
#include <cmath>
#include"vec_ODE.h"
#include"function_ODE.h"


using namespace std;
int main(int argc,char *argv[]) {

    if(argc<6){
        cerr<<"Input Error!"<<endl;
        exit(argc);
    }

    unsigned int n=atoi(argv[1]);

    if(argc!=n+5){
        cerr<<"Input Error!"<<endl;
        exit(argc);
    }

    double t=atof(argv[2]);
    double t_end=atof(argv[3]);
    double h=atof(argv[4]);

    vec<double> y=vec<double>(n);
    for(unsigned int i=0;i<n;i++)
        y[i]=atof(argv[i+5]);

    // create the result.txt
    ofstream writer;
    writer.open("result.txt",fstream::out);
    if(!writer.is_open()){
        cerr<<"Fail to create result!"<<endl;
        exit(1);
    }

    if(t_end<t) h=-h;
    unsigned int steps=(t_end-t)/h+1;
    vec<double> k1=vec<double>(n);
    vec<double> k2=vec<double>(n);
    vec<double> k3=vec<double>(n);
    vec<double> k4=vec<double>(n);
    vec<double> y_delta=vec<double>(n);
    for(unsigned int i=0;i<steps;i++){
        writer<<t<<" ";
        for(unsigned int j=0;j<n;j++)
            writer<<y[j]<<" ";
        writer<<endl;
     //  Runge-Kutta method
        k1=fun(t,y)*h;
        y_delta=y+k1/2;
        k2=fun(t+h/2, y_delta)*h;
        y_delta=y+k2/2;
        k3=fun(t+h/2, y_delta)*h;
        y_delta=y+k3;
        k4=fun(t+h/2, y_delta)*h;

        y=y+(k1+k2*2+k3*2+k4)/6;
        t=t+h;
    }

    writer.close();

    return 0;
}