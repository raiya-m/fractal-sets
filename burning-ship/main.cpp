#include <iostream>
#include <fstream>
#include <cmath> 

/* 

same concept as mandelbrot, except absolute values are taken; insanely cool visualization

*/

//mapping to real function
int map_to_real() {

}

//mapping to imaginary function
int map_to_imaginary() {

}
//determining the escape value function
int find_escape() {
    
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

    for (int y = 0; y < image_height; ++y) {
        for (int x = 0; x < image_width; ++x) {
            //call functions

        }
    }
    std::cout << "complete!" << std::endl;
    return 0; 
}