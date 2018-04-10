#include "PID.h"
#include <iostream>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	  PID::Kp = Kp;
	  PID::Ki = Ki;
	  PID::Kd = Kd;
}

void PID::UpdateError(double cte) {

	  static double prev_cte = 0;
	  static double sum_cte = 0;

	  sum_cte = sum_cte + cte;

	  p_error = cte;
	  i_error = sum_cte;
	  d_error = cte - prev_cte;

	  prev_cte = cte;
}
