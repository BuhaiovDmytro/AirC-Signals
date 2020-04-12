//
// Created by dmytro on 12/04/2020.
//

#ifndef INC_1_SIGNALS_OTHER_H
#define INC_1_SIGNALS_OTHER_H

#include <vector>
#include <fstream>

using namespace std;

vector<float> signal_union(vector<float> old_area, vector<float> new_signal, int place);
void csv_writer(vector<float> signals, ofstream& file);

#endif //INC_1_SIGNALS_OTHER_H
