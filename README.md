# Solving-ODE-in-Python-by-Calling-External-Procedure

This is an example of solving ODE in python by calling external procedure written by C++ to enhance performance. The 'sample.py' will create the 'function_ODE.cpp' which describes continuous function f(x,y) in ODEs y'=f(x,y). Then compile, link from all source files to generate and run the executable ODE_solver, to get the result.txt, then the python routine will load result.txt then plot the results.
