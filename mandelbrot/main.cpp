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

some variable descriptions...
max_n -> maximum number of iterations before we decide if a point escapes 
min_r -> minimum real number value 
max_r -> maximum real number value 
min_i -> minimum imaginary value 
max_i -> maximum imaginary  value 
*/

int find_escape(double cr, double ci, int max_iterations) {
    int i = 0; 
    double zr = 0.0; 
    double zi = 0.0; 

    while (i < max_iterations && zr * zr + zi * zi < 4.0) { //predet calculation to determine if ∈ mandelbrot
        double temp = zr * zr - zi * zi + cr; 
        zi = 2.0 * zr * zi + ci;
        zr = temp; 
        i++;
    }
    return i;
}

double map_to_real (int x, int image_width, double min_r, double max_r) {
    double range = max_r - min_r; 
    return x * (range/image_width) + min_r; 

}

double map_to_imaginary (int y, int image_height, double min_i, double max_i) {
    double range = max_i - min_i; 
    return y * (range/image_height) + min_i;
}

int main () {
    std::ifstream fin("input.txt"); 

    int image_width; 
    int image_height; 
    int max_n;

    double min_r; 
    double max_r; 
    double min_i; 
    double max_i;

    if (!fin) {
        std::cout << "input.txt was not found...using some default values to model." << std::endl;
        image_width = 512;
        image_height = 512; 
        max_n = 255;

        min_r = -1.5;
        max_r = 0.7; 
        min_i = -1.0; 
        max_i = 1.0;
    }

    else {
        fin >> image_width >> image_height >> max_n;
        fin >> min_r >> max_r >> min_i >> max_i;
    }
    
    //the ppm header
    std::ofstream fout("output_image.ppm");
    
    fout << "P3" << std::endl; //to identify that we are using a ppm file
    fout << image_width << " " << image_height << std::endl; 
    fout << "256" << std::endl; 

    //pixel by pixel: 
    for (int y = 0; y < image_height; y++) { 
        for (int x = 0; x < image_width; x++) {
            double cr = map_to_real(x, image_width, min_r, max_r);
            double ci = map_to_imaginary(y, image_height, min_i, max_i);

            int n = find_escape(cr, ci, max_n); 

            //map to rgb value (this'll be greyscale)
            int r = (n % 256); 
            int g = (n % 256);
            int b = (n % 256);

            fout << r << " " << g << " " << b << " ";
        }
        fout << std::endl; 
    }
    std::cout << "complete!" << std::endl; 
    return 0; 
}