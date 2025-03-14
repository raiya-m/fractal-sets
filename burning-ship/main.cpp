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


    
    //read from input.txt
    //create ppm header from input.txt
    //nested pixel-by-pixel loop & call functions
    //within loop output map to set rgb values 
    //output 
}
