# **PID Control**

---

**PID Controller Project**

The goals / steps of this project are the following:

* Implementation of the PID controller in C++.
* Tuning of the proportional, differential and integral tau parameters.

[//]: # (Image References)

[image1]: ./output/Simulator.png "Simulator"

## Rubric Points

Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/824/view) individually and describe how I addressed each point in my implementation.  

---


### Algorithm structure and processing flow

The algorithm is divided in the following source code files located in `/src`:

`main.cpp` -> Main routine to read the CTE and call the PID functions implemented in the `PID` class.

`PID.cpp` -> Initialization of tau parameters and update of proportional, integral and differential errors.

`twiddle.cpp` -> Twiddle algorithm for parameter optimization.

#### 1. Implementation

The PID procedure consists on the calculation of the steering angle during each cycle in function of the CTE. The `main` routine reads the mentioned CTE and calculates the error corresponding to each PID part via `UpdateErrors` (`PID` class). The tau parameters are applied to each of the calculated errors and finally the steering angle is obtained.

It is possible to stimulate the tau parameters so that their values are constant during the whole execution. To achieve this, the desired values can be set via `Init` function of `PID`. It is also possible to modify the parameters during execution through the class `Twiddle`, in order to find optimal values. For activating the twiddle functionality, the compiler switch `TWIDDLE` has been specified in `main`. If defined, the functions `CalcRunError` and `Twiddle_main` are cyclic called in the `main` routine. If not, the tau parameters will be constant and with the values defined in `Init`.

#### 2. PID components effect

After implementing the PID controller simulations have been done with different values of the tau parameters, using both twiddle and manual tuning. The following conclusions have been made:

-For this simulator, it is not needed to apply the integral component to the steering angle. Positive values of the integral tau have made that the car goes off the road. The possible reason is that there is no systematic bias in the wheels of the car. Therefore, the integral tau parameter has been always tuned with the value `0`.

-As expected, the proportional component is the most important of the controller. It defines the main steering angle of the car. If the proportional tau parameter is `0` (no proportional component), the car goes always off the road.

-The differential components corrects the oscillations produced by the turn produced by the proportional component. The most accurate the differential tau parameter is, the less oscillations the car suffers.

#### 3. Tau parameters tuning

Regarding tuning of the tau parameters, it has been found that the optimal configuration of the tau parameters depends on the car velocity. Therefore, a different throttle will make that the parameter configuration needs to be reworked.

Regarding the methods used for tuning, the twiddle algorithm has been implemented and used. It has been found that it does not work well when determining the optimal configuration without having an estimated idea of which the optimal values could be. The reason is that, when modifying the parameters with high ranges, the car at some point gets off the road. Therefore, for this project the chosen approach has been to do manual tuning of the parameters, and once an initial estimation has been done, twiddle has been used for fine-tuning of the final parameter values.

#### 4. Results

It has been found that an appropiate configuration of the parameters is:

Tau_proportional -> `3.1436`

Tau_differential -> `2.0891`

Tau_integral -> `0`

With this configuration and a constant throttle of `0.1`, the car behaves as shown in QPWEOIRUQPOEWURQ

#### 5. Possible improvements

As possible improvements, an additional research of optimal parameter configurations for higher car velocities could be done. As mentioned, the current configuration works fine for a throttle of `0.1`, but it is of course interesting to make the car complete the whole lap with a velocity as high as possible. Therefore it will be investigated in the future which top velocity can be reached.
