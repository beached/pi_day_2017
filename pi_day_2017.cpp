// The MIT License (MIT)
//
// Copyright (c) 2017 Darrell Wright
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <random>

int main( int, char** ) {
	intmax_t const radius = 10000;
	size_t const num_values = 1'000'000;
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng{ rd( ) };    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<intmax_t> uni{ -radius, radius }; // guaranteed unbiased

	size_t count = 0;
	size_t in_circle = 0;
	auto const radius2 = radius*radius;
	for( intmax_t n=0; n<num_values; ++n ) {
		auto const x = uni( rng );
		auto const y = uni( rng );
		auto const d2 = x*x + y*y; 
		++count;
		if( d2 < radius2 ) {
			++in_circle;
		}
	}
	std::cout << "With a radius of " << radius << " and a sample size of " << num_values << '\n';
	std::cout << "Estimate = " << (4.0*static_cast<double>(in_circle))/static_cast<double>(count) << '\n';
	return EXIT_SUCCESS;
}


