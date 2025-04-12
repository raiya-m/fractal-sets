#include <iostream>
#include <fstream>
#include <cmath> 

/* 

Fractal based on newton’s method; visualizes convergence to polynomial roots

The newton fractal is a graphical representation of the behavior of newton's method for finding the roots of a 
complex function, typically \( f(z) = z^3 - 1 \). The function has three distinct roots in the complex plane, and 
each point is colored based on which root it converges to and how quickly. Unlike mandelbrot-based fractals, there’s no “escape”
— instead, you're observing which attractor each initial complex guess is drawn toward.

The formula used is derived directly from newton's method:
  z = z - (z^3 - 1)/(3z^2)
and this simplifies to:  
  z = z - (z³ - 1) / (3z²)

Each pixel's starting value is treated as a complex number, and the iteration tracks how it converges to one of 
the three cube roots of unity. The boundary regions, where convergence is somewhat slow or ambiguous, create the fractal. 

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

//distance between complex numbers
double dist(double zr, double zi, double r, double i) {
    return sqrt((zr - r) * (zr - r) + (zi - i) * (zi - i));
}

//determining convergence to one of the roots
int find_root_index(double zr, double zi) {
    // roots of z^3 = 1
    double roots_r[3] = {1.0, -0.5, -0.5};
    double roots_i[3] = {0.0, sqrt(3)/2.0, -sqrt(3)/2.0};

    for (int i = 0; i < 3; i++) {
        if (dist(zr, zi, roots_r[i], roots_i[i]) < 0.001)
            return i;
    }
    return -1; //did not converge to any root
}

//determining the escape value function (iterations)
int find_escape(double& zr, double& zi, int max_iterations) {
    int i = 0;

    while (i < max_iterations) {
        double r2 = zr * zr;
        double i2 = zi * zi;

        double denom = 3.0 * (r2 - i2);
        double zi2 = 2.0 * zr * zi;

        if (denom * denom + zi2 * zi2 == 0.0)
            break;

        // z^3 - 1
        double num_r = zr * (r2 - 3 * i2) - 1;
        double num_i = zi * (3 * r2 - i2);

        // z = z - f(z)/f'(z)
        double temp_r = (num_r * r2 + num_i * zi2) / (denom * denom + zi2 * zi2);
        double temp_i = (num_i * r2 - num_r * zi2) / (denom * denom + zi2 * zi2);

        zr = zr - temp_r;
        zi = zi - temp_i;

        if (find_root_index(zr, zi) != -1)
            break;

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
            double zr = map_to_real(x, image_width, min_r, max_r);
            double zi = map_to_imaginary(y, image_height, min_i, max_i);

            double orig_zr = zr;
            double orig_zi = zi;

            int n = find_escape(zr, zi, max_n); 
            int root_index = find_root_index(zr, zi);

            //color by root index
            int r = 0, g = 0, b = 0;
            if (root_index == 0) {
                r = (n * 5) % 256;
                g = 0;
                b = 0;
            }
            else if (root_index == 1) {
                r = 0;
                g = (n * 5) % 256;
                b = 0;
            }
            else if (root_index == 2) {
                r = 0;
                g = 0;
                b = (n * 5) % 256;
            }

            fout << r << " " << g << " " << b << " ";
        }
        fout << std::endl; 
    }
    std::cout << "complete!" << std::endl; 
    return 0; 
}
