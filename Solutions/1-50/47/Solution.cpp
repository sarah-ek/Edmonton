#include "../../Headers/Edmonton.hpp"
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
For this problem we need to make sure that the distinct number of factors that a given function has is exactly 4.
So in order to optimize this for time/speed we can generate the primes and go through the number, counting the number of prime factors.
Before we return it we can add it to cache. When we search that number again later on, we have the cached results ready for us. 
*/
int primeFactorCount(int n, const vector<bool> &primes) {
	// We can first check our cache to see if we processed this number before.
	static unordered_map<int, int> cache;
	if(cache.find(n) != cache.end()) {
		return cache.at(n);
	}
	int count = 0;
	for(int i = 2; i <= primes.size(); i++) {
		if(n % i == 0 && Edmonton::isPrime(i, primes)) {
			count++;
		}
	}
	cache.insert({n, count});
	return count;
}

int main(int argc, char *argv[]) {
	// Generate the list for the first ten-thousand primes so we can use it to count prime factors. Higher numbers are unlikely.
	vector<bool> primes = Edmonton::primesUpto(10'000);
	// Minimum starting number.
	int j = 210;
	// Loop till we get to what we need.
	while(true) {
		if(primeFactorCount(j, primes) == 4) {
			if(primeFactorCount(j - 1, primes) == 4) {
				if(primeFactorCount(j - 2, primes) == 4) {
					if(primeFactorCount(j - 3, primes) == 4) {
						cout << j - 3 << endl;
						break;
					}
				}
			}
		}
		cout << j << endl;
	}
	return 0;
}