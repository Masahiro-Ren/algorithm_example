#include <iostream>
#include <ctime>
#include <random>

int main()
{
    // use rand_device to generate seed
    std::random_device rnd;
    // Mersenne Twister as random generator 
    std::mt19937 rng(rnd());

    // to generate integer random number
    std::uniform_int_distribution<int> uni(0, 100);
    // to generate float random number
    std::uniform_real_distribution<float> unf(0.0, 1.0);

    int rand_int = uni(rng);
    float rand_float = unf(rng);

    std::cout << "random integer : " << rand_int << std::endl;
    std::cout << "random float : " << rand_float << std::endl; 

    return 0;
}