#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    // below this is used instead of _ which is more convenient
    this ->Kp = Kp;
    this ->Ki = Ki;
    this ->Kd = Kd;

    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte) {
    // if off to right, we wanna steer back to centre
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

}

double PID::TotalError() {
    return Kp*p_error + Ki*i_error + Kd*d_error;
}

