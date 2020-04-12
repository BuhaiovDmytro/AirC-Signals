//
// Created by dmytro on 12/04/2020.
//

#include "Other.h"

vector<float> signal_union(vector<float> old_area, vector<float> new_signal, int place){
    for(unsigned int i = 0; i < new_signal.size(); i++){
        if((place + i) < old_area.size()) {
            old_area[place + i] = old_area[place + i] + new_signal[i];
        }
    }

    return old_area;
}

void csv_writer(vector<float> signals, ofstream& file){
    for(unsigned int i = 0; i < signals.size(); i++){
        file << signals[i] << ";\n";
    }
}
