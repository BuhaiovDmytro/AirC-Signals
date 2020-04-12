//
// Created by dmytro on 07/04/2020.
//

#ifndef INC_1_SIGNALS_GENERATOR_H
#define INC_1_SIGNALS_GENERATOR_H

#include <vector>
#include <cmath>
#include <fstream>


using namespace std;

vector<float> sin_generator(float amp, int freq, float shift, int duration, int start_time, int finish_time);
vector<float> tri_generator(float amp, int freq, float shift, int duration, int start_time, int finish_time);


#endif //INC_1_SIGNALS_GENERATOR_H
