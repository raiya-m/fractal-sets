#include <iostream>
#include <fstream>
#include <cmath> 

/* 

Fractal based on newton’s method; visualizes convergence to polynomial roots

The Newton fractal is a graphical representation of the behavior of Newton’s method for finding the roots of a 
complex function, typically \( f(z) = z^3 - 1 \). The function has three distinct roots in the complex plane, and 
each point is colored based on which root it converges to and how quickly. Unlike mandelbrot-based fractals, there’s no “escape”
— instead, you're observing which attractor each initial complex guess is drawn toward.

The formula used here is derived directly from Newton's method:
  z = z - (z^3 - 1)/(3z^2)
and this simplifies to:  
  z = z - (z³ - 1) / (3z²)

Each pixel's starting value is treated as a complex number, and the iteration tracks how it converges to one of 
the three cube roots of unity. The boundary regions — where convergence is slow or ambiguous — create the fractal. 

*/

