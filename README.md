**Some quick and simple models of my favourite fractal sets.** Some notes I wrote for myself: <br>

**The Mandelbrot Set** <br>
The Mandelbrot set consists of all complex numbers, c, for which the following recursive sequence remains bounded:  
  z_n+1 = z_n^2 + c

If the sequence remains finite for an infinite number of iterations, then c ∈ Mandelbrot set. 
If |z_n| grows beyond a certain bound, 2, then c ∉ Mandelbrot set, because we assume it keeps growing to infinity and 
the point has "reached escape". 

To generate Mandelbrot images, each pixel (x,y) will be mapped to a corresponding complex number c. We will then iterate
the Mandelbrot formula for this c, counting the number of iterations it takes for the sequence to escape the iteration limit. 
This count will then be translated into a specific rgb colour. <br><br>

**The Burning Ship Fractal** <br>
The burning ship fractal is a variation of the Mandelbrot set. What sets it apart is the use of absolute values in the 
iteration formula, specifically applied to the real and imaginary components of the complex number during each update. 
This results in a radically different visual structure from the Mandelbrot set. 

The core formula of the burning ship is:  
  z = (|Re(z)| + i·|Im(z)|)² + c

In practical terms, this means that before squaring the complex number z, both its real and imaginary parts are made positive. 
This seemingly small twist causes significant changes in the visualization, especially in the lower half of the complex plane. 
The symmetry is also different: unlike the Mandelbrot set's symmetry across the real axis, the Burning Ship has symmetry only 
across the x-axis (real axis), leading to a lopsided appearance.

Due to its more complex and jagged boundary structure, the burning ship fractal is often slower to render than the mandelbrot 
set and exhibits higher sensitivity to pixel resolution and escape conditions. Just like the mandelbrot set, each point in 
the complex plane is iterated to test for divergence, and those that do not "escape" within a fixed number of iterations are 
considered part of the fractal and colored accordingly.

**The Newton Fractal** <br>
The newton fractal is a graphical representation of the behavior of newton's method for finding the roots of a 
complex function, typically f(z) = z³ − 1. The function has three distinct roots in the complex plane, and 
each point is colored based on which root it converges to and how quickly. Unlike mandelbrot-based fractals, there’s no “escape”
— instead, you're observing which attractor each initial complex guess is drawn toward.

The formula used is derived directly from newton's method:<br>
  z = z − (z³ − 1) / (3z²) <br>
and this simplifies to:  <br>
  z = z - (z³ - 1) / (3z²)

Each pixel's starting value is treated as a complex number, and the iteration tracks how it converges to one of 
the three cube roots of unity. The boundary regions, where convergence is somewhat slow or ambiguous, create the fractal. <br><br>
