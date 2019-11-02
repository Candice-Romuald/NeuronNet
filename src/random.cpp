#include "random.h"
//#include <iostream> //?

RandomNumbers::RandomNumbers (unsigned long int s)
{
	//throw s < 0 ??
	 if (s == 0) {
        std::random_device rd;
        seed = rd();
    } else {
		seed = s;
	}
	rng = std::mt19937(seed);
}

double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution<> unif(lower, upper);
	return unif (rng);
}
 

void RandomNumbers::uniform_double(std::vector<double>& l, double lower, double upper)
{
	std::uniform_real_distribution<> unif(lower, upper);
	for (auto& nbr: l) {
		nbr = unif (rng);
	}
}
void RandomNumbers::normal(std::vector<double>& l, double mean, double sd){
	std::normal_distribution<> norm(mean, sd);
	for (auto& nbr: l) {
		nbr = norm (rng);
	}
}
double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<> norm(mean, sd);
	return norm(rng);
}
void RandomNumbers::poisson(std::vector<int>& l, double mean){
	std::poisson_distribution<int> pois (mean);
	for (auto& dab: l){
		dab = pois(rng);
	}
}
int RandomNumbers::poisson(double mean){
	std::poisson_distribution<int> pois (mean);
	return pois(rng);
}
