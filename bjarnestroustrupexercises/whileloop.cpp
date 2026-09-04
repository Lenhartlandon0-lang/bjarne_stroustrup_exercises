//
//  whileloop.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/7/26.
//

#include <iostream>
#include <vector>
#include <string_view>
#include <charconv>
#include <system_error>
#include <utility>
#include <unordered_map>
#include <algorithm>
using namespace std;

pair<double, string> parse_double( string in ) {
    //the responsibility of this function is ONLY to take an inputted string and seperate it as a double and unit.
    pair <double, string> parsedvalues;
    const string_view s = in;
    double result{};
    auto [ptr, ec] = from_chars(s.data(), s.data() + s.size(), result);
    if (ec == errc()) {
        string unit = ptr;
        double value = result;
        parsedvalues.first = value;
        parsedvalues.second = unit;
    }
    else if (ec == errc::invalid_argument) {
        cout << "Please enter a number followed by a unit. \n";
    }
    return parsedvalues;
    
}
double convert_to_meters ( pair<double, string> result ) {
    double mval = -1.0;
    vector<double> nlist;
    unordered_map<string, double> conversion_rates {{"cm", 0.0100},
                                                    {"in", 0.0254},
                                                    {"ft", 0.3048},
                                                    {"m", 1.0000}};
    if ( auto search = conversion_rates.find(result.second); search != conversion_rates.end() ) {
        mval = search->second * result.first;
        }
    else {
        cout << "Please enter a valid unit! \n";
        }
    return mval;
}
int main() {
    string input;
    vector<double> nlist;
    double min{}; double max{};
    while ( cin >> input ) {
        cout << "You entered " << input << endl;
        double mv = convert_to_meters(parse_double(input));
        if ( mv != -1.0 ) {
            if ( mv < min ) {
                cout << "You entered the smallest (meter) value so far, " << mv << "!\n";
            }
            if (mv > max ) {
                cout << "You entered the largest (meter) value so far, " << mv << "!\n";
            }
            cout << "That is " << mv << " meters\n";
            nlist.push_back(mv);
            auto mm = ranges::minmax_element(nlist);
            min = *mm.min;
            max = *mm.max;
        }
    }
}
// pure slop
