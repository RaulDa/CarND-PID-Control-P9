#include <iostream>
#include "twiddle.h"

Twiddle::Twiddle() {

	  // initialize counters
	  counterRun = 0;
	  counterNoRuns = 0;

	  // initialize error variables
	  finalerr = 99999999;
	  besterr = 99999999;

	  // initialize parameter values
	  p[0] = 1;
	  p[1] = 1;
	  p[2] = 0.01;

	  // initialize parameter increments
	  dp[0] = 1;
	  dp[1] = 1;
	  dp[2] = 0.25;

	  // define tolerance
	  tol = 0.0002;

	  // initialize amount of increment and parameter index
	  type_increment = 0;
	  parameter_index = 0;
}

Twiddle::~Twiddle() {}

void Twiddle::CalcRunError(double cte) {

	static double err = 0;

	// increment current run counter
	counterRun++;

	if(counterRun >= 30){
		// increment current run accumulated error
		err = err + cte*cte;
	}
	if(counterRun >= 60){
		// define final run error
		finalerr = err / 30;

		// reset counter and error
		counterRun = 0;
		err = 0;

		// after finalizing run, increment no. of runs counter
		counterNoRuns++;
	}
}

void Twiddle::Twiddle_main() {

	static double prev_counterNoRuns = 0;

	// processing if current run has finished
	if(prev_counterNoRuns != counterNoRuns){

		// processing if the desired accuracy has not been yet reached
		if(dp[0]+dp[1]+dp[2] > tol){

			if(type_increment == 0){
				// first parameter increment
				p[parameter_index] += dp[parameter_index];
				type_increment = 1;
			}
			else if(type_increment == 1){

				if (finalerr < besterr){
					// save improved error value
					besterr = finalerr;
					dp[parameter_index] *= 1.1;

					// go to next parameter
					type_increment = 0;
					if(parameter_index < 1){
						parameter_index++;
					}
					else{
						parameter_index = 0;
					}

				}
				else{
					// second parameter increment
					p[parameter_index] -= 2 * dp[parameter_index];
					type_increment = 2;
				}
			}
			else{

				if (finalerr < besterr){
					// save improved error value
					besterr = finalerr;
					dp[parameter_index] *= 1.1;

					// go to next parameter
					type_increment = 0;
					if(parameter_index < 1){
						parameter_index++;
					}
					else{
						parameter_index = 0;
					}

				}
				else{
					// third parameter increment
					p[parameter_index] += dp[parameter_index];
					dp[parameter_index] *= 0.9;

					// go to next parameter
					type_increment = 0;
					if(parameter_index < 1){
						parameter_index++;
					}
					else{
						parameter_index = 0;
					}

				}
			}
		}
		else{
			  // print calculated parameters
	          std::cout << "p[0]: " << p[0] << " p[1]: " << p[1] << " p[2]: " << p[2] << std::endl;
		}
	}

	prev_counterNoRuns = counterNoRuns;
}

