//
// Created by dmytro on 11/04/2020.
//

#include "Menu.h"

std::vector<float> inline StringSplit(const std::string& source, const char* delimiter = ";", bool keepEmpty = false)
{
    std::vector<float> results;

    size_t prev = 0;
    size_t next = 0;

    while ((next = source.find_first_of(delimiter, prev)) != std::string::npos)
    {
        if (keepEmpty || (next - prev != 0))
        {
            results.push_back(stof(source.substr(prev, next - prev)));
        }
        prev = next + 1;
    }

    if (prev < source.size())
    {
        results.push_back(stof(source.substr(prev)));
    }

    return results;
}

int menu(){
    bool flag = 1;
    int menu, new_area_size;
    vector<float> old_area;
    while(1) {
        if(flag){
            cout << "\n\n Choose the alternative:";
            cout << "\n 1. Create new area";
            cout << "\n 2. Use existing area";
            cout << "\n 3. Quit";
            cout << "\n>> ";
            cin >> menu;
            switch(menu){
                case 1:
                    remove("signals.csv");
                    cout << "\n Input size of the new area ";
                    cin >> new_area_size;
                    for(unsigned int i = 0; i < new_area_size; i++){
                        old_area.push_back(0);
                    }
                    break;
                case 2: {
                    string tmp;
                    vector<float> token;
                    ifstream csv_signals_test;
                    csv_signals_test.open("signals.csv");
                    if (!csv_signals_test) {
                        cout << "\nArea opened";
                    }
                    while (getline(csv_signals_test, tmp)) {
                        token = StringSplit(tmp);
                        old_area.push_back(token[0]);
                    }
                    csv_signals_test.close();
                    break;
                }
                case 3:
                    return 0;
            }
        }
        cout << "\n\n Main menu:";
        cout << "\n 1. Add new signal";
        cout << "\n 2. Remove area";
        cout << "\n 3. Return";
        cout << "\n 4. Quit";
        cout << "\n>> ";
        cin >> menu;
        switch (menu) {
            case 1: {
                int freq, duration, start_time, finish_time;
                float amp, shift;
                vector<float> signal;
                cout << "\n Add new signal:";
                cout << "\n 1. Sin";
                cout << "\n 2. Triangle";
                cout << "\n 3. Return";
                cout << "\n>> ";
                cin >> menu;
                switch (menu)
                    case 1: {
                        cout << "\n Sin:";
                        cout << "\n Amplitude(float): ";
                        cin >> amp;
                        cout << "\n Frequency(int): ";
                        cin >> freq;
                        cout << "\n Phase shift(float): ";
                        cin >> shift;
                        cout << "\n Signal duration in ms(int): ";
                        cin >> duration;
                        cout << "\n Recording start time in ms(int): ";
                        cin >> start_time;
                        cout << "\n Recording finish time in ms(int): ";
                        cin >> finish_time;
                        signal = sin_generator(amp, freq, shift, duration, start_time, finish_time);
                        break;
                        case 2:
                            cout << "\n Triangle:";
                        cout << "\n Amplitude(float): ";
                        cin >> amp;
                        cout << "\n Frequency(int): ";
                        cin >> freq;
                        cout << "\n Phase shift(float): ";
                        cin >> shift;
                        cout << "\n Signal duration in ms(int): ";
                        cin >> duration;
                        cout << "\n Recording start time in ms(int): ";
                        cin >> start_time;
                        cout << "\n Recording finish time in ms(int): ";
                        cin >> finish_time;
                        signal = tri_generator(amp, freq, shift, duration, start_time, finish_time);
                        break;
                        case 3:
                            break;
                    }
                if(menu != 3) {
                    vector<float> united_area;
                    ofstream csv_signals_upd;
                    csv_signals_upd.open("signals.csv");
                    int place = 0;
                    if(old_area.capacity() != 0) {
                        cout << "\n Input place  between 0 and " << old_area.size() << " where to add new signal: ";
                        cin >> place;
                    }
                    united_area = signal_union(old_area, signal, place);
                    csv_writer(united_area, csv_signals_upd);
                    csv_signals_upd.close();
                    cout << "\nNew signal added to an area";
                }
                flag = 0;
                break;
            }
            case 2: {
                if (remove("signals.csv") != 0)
                    std::cout << "\nError while removing area";
                else
                    std::cout << "\nArea removed";
                flag = 1;
                break;
            }
            case 3:
                flag = 1;
                break;
            case 4:
                return 0;
        }
    }
}
