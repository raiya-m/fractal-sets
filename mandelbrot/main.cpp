#include <fstream>
#include <iostream> 

/* 
hello there! a brief definition...
the Mandelbrot set consists of all complex numbers, c, for which the following recursive sequence remains bounded: 
z_n+1 = z_n^2 + c

conditions...
if the sequence remains finite for an infinite number of iterations, then c ∈ Mandelbrot set. 
if |z_n| grows beyond a certain bound, 2, then c ∉ Mandelbrot set, because we assume it just keeps growing to infinity and 
the point has "reached escape". 

strategy...
to generate Mandelbrot images, each pixel (x,y) will be mapped to a corresponding complex number c. we will then iterate
the Mandelbrot formula for this c, counting the number of iterations it takes for the sequence to escape the iteration limit. 
this count will then be translated into a specific rgb colour!

some variable definitions...
max_n -> maximum number of iterations before we decide if a point escapes 
min_r -> minimum real number value 
max_r -> maximum real number value 
min_i -> minimum imaginary value 
max_i -> maximum imaginary  value 
*/

