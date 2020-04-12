//
// Created by dmytro on 07/04/2020.
//

#include "Generator.h"

vector<float> sin_generator(float amp, int freq, float shift, int duration, int start_time, int finish_time){
    if(start_time < finish_time) {
        const float pi = 3.14;
        vector<float> result;
        for (unsigned int i = 0; i < duration; i++) {
            if ((i >= start_time) && (i <= finish_time)) {
                result.push_back(amp * sin((2 * pi * freq * i) + shift));
            }
        }

        return result;
    }
}

vector<float> tri_generator(float amp, int freq, float shift, int duration, int start_time, int finish_time){
    if(start_time < finish_time) {
        const float pi = 3.14;
        vector<float> result;
        for (unsigned int i = 0; i < duration; i++) {
            if ((i >= start_time) && (i <= finish_time)) {
                result.push_back(((2 * amp) / pi) * asin(sin((2 * pi * freq * i) + shift)));
            }
        }

        return result;
    }
}

