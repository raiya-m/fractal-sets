#include <iostream>
#include <fstream>
#include <cmath> 

/* 

The burning ship fractal is a variation of the Mandelbrot set. What sets it apart is the use of absolute values in the 
iteration formula, specifically applied to the real and imaginary components of the complex number during each update. 
This results in a radically different visual structure from the Mandelbrot set, giving rise to a fractal that looks like 
a burning ship — hence the name.

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

*/

//map to real
double map_to_real (int x, int image_width, double min_r, double max_r) {
    double range = max_r - min_r; 
    return x * (range/image_width) + min_r; 
}

//map to im
double map_to_imaginary (int y, int image_height, double min_i, double max_i) {
    double range = max_i - min_i; 
    return y * (range/image_height) + min_i;
}

//determining the escape value function
int find_escape(double cr, double ci, int max_iterations) {
    int i = 0; 
    double zr = 0.0; 
    double zi = 0.0; 

    while (i < max_iterations && zr * zr + zi * zi < 4.0) { //predet calculation to determine if ∈ burning ship
        double temp = zr * zr - zi * zi + cr; 
        zi = fabs(2.0 * zr * zi) + ci; //make absolute
        zr = fabs(temp); 
        i++;
    }
    return i;
}

int main () {
    std::ifstream fin("input.txt"); 
    
    //some variable definitions
    int max_n; 
    int image_width; 
    int image_height; 

    int min_i; 
    int max_i; 
    int min_r; 
    int max_r;

    if (!fin) {
        std::cout << "input.txt was not found." << std::endl;
        fin.close();
        return 0; 
    }

    else {
        fin >> image_height >> image_width >> max_n; 
        fin >> min_i >> max_i >> min_r >> max_r; 
    }

    std::ofstream fout("output.ppm");

    fout << "P3" << std::endl;
    fout << image_width << " " << image_height << std::endl; 
    fout << "256" << std::endl;

    //pixel by pixel: 
    for (int y = 0; y < image_height; y++) { 
        for (int x = 0; x < image_width; x++) {
            double cr = map_to_real(x, image_width, min_r, max_r);
            double ci = map_to_imaginary(y, image_height, min_i, max_i);

            int n = find_escape(cr, ci, max_n); 

            //map to rgb value (this'll be greyscale)
            int r = (n % 255); 
            int g = (n % 255);
            int b = (n % 255);

            fout << r << " " << g << " " << b << " ";
        }
        fout << std::endl; 
    }
    std::cout << "complete!" << std::endl; 
    return 0; 
}
