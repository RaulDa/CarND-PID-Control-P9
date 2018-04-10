#ifndef TWIDDLE_H_
#define TWIDDLE_H_

using namespace std;

class Twiddle {
public:

  // cycle counter for single run
  double counterRun;
  // number of performed runs
  double counterNoRuns;

  // final error of single run
  double finalerr;
  // best error
  double besterr;

  // parameter values
  double p[3];
  // parameter increment
  double dp[3];

  // tolerance
  double tol;

  // amount of parameter increment
  int type_increment;
  // parameter index
  int parameter_index;

  /**
  * Constructor.
  */
  Twiddle();

  /**
  * Destructor.
  */
  virtual ~Twiddle();

  /**
  * Calculate total error for current twiddle run cycle
  * @param cte CTE
  */
  void CalcRunError(double cte);

  /**
  * Main routine for controlling the parameter increments
  */
  void Twiddle_main();

};

#endif /* TWIDDLE_H_ */
