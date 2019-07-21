#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
 VectorXd RMSE(4);
 RMSE << 0, 0, 0, 0;
 // Getting the squared difference

 for (unsigned int i=0;i < estimations.size(); ++i){
   VectorXd residual = estimations[i] - ground_truth[i];
   residual = residual.array()*residual.array();
   RMSE += residual;
 }
 // taking the average value for rmse
 RMSE /= estimations.size();
 RMSE = RMSE.array().sqrt();
 return RMSE;
}