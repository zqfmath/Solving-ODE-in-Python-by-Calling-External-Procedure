import os
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

#Parameters
n=3
x0=0
x1=20
h=0.01
y1=10
y2=10
y3=10

Z=[n,x0,x1,h,y1,y2,y3]
para=''
for x in Z:
    para=para+str(x)+' '
print(para)


if not os.path.exists('temp_ODE'):
    os.mkdir('temp_ODE')
#write the function file
file=open('temp_ODE/function_ODE.cpp',"w+")
file.write('#include <cmath>\n')
file.write('#include"../Source_Codes/vec_ODE.h"\n')

file.write('vec<double> fun(double t, vec<double> &x){\n')
file.write('vec<double> f_value(%d);\n'%n)

file.write('f_value[0]=10*(x[1]-x[0]);'+'\n')
file.write('f_value[1]=x[0]*(28-x[2])-x[1];'+'\n')
file.write('f_value[2]=x[0]*x[1]-8*x[2]/3;'+'\n')

file.write(' return f_value;\n}')

file.close()

#excutes solver
os.system('g++ Source_Codes/ODE_solver.cpp -o temp_ODE/ODE_solver')
os.system('./temp_ODE/ODE_solver '+para)

#load result
result=np.loadtxt('result.txt')

t=result[:,0]
X=result[:,1]
Y=result[:,2]
Z=result[:,3]

#plot the result
fig=plt.figure()
ax=fig.gca(projection='3d')
ax.plot(X,Y,Z)
plt.show()

