#include "Analyzer.h"
#include <cmath>
#include <algorithm> 
#include <limits>    
#include <stdexcept> 
#include <cstdlib>   

double Analysing::Get_Duration(std::vector<std::pair<std::string, std::string> > &data){

    if (data.empty()) {
        throw std::runtime_error("Empty data vector");
    }

    return std::stod(data[data.size() - 1].first);
}

double Analysing::Get_Max_Sensor_value(std::vector<std::pair<std::string, std::string> > &data){

    if (data.empty()) {
        throw std::runtime_error("Empty data vector");
    }

    double max_Val = std::numeric_limits<double>::lowest();

    for(auto s = data.begin() + 1; s != data.end(); ++s){
        if(std::stod(s->second) > max_Val){
            max_Val = stod(s->second);
        }
    }

    return max_Val;
}

double Analysing::Get_Min_Sensor_value(std::vector<std::pair<std::string, std::string> > &data){

    if (data.empty()) {
        throw std::runtime_error("Empty data vector");
    }

    double min_Val = std::numeric_limits<double>::max();

    for(auto s = data.begin() + 1; s != data.end(); ++s){
        if(std::stod(s->second) < min_Val){
            min_Val = stod(s->second);
        }
    }

    return min_Val;
}

double Analysing::Get_Avg_Sensor_value(std::vector<std::pair<std::string, std::string> > &data){

    if (data.empty()) {
        throw std::runtime_error("Empty data vector");
    }

    int amount = data.size() - 1;
    double sum = 0.0;

    for(auto s = data.begin() + 1; s != data.end(); ++s){
        sum = sum + std::stod(s->second);
    }

    return sum / amount;
}


double Analysing::Get_Variance_value(std::vector<std::pair<std::string, std::string> > &data){

    if (data.empty()) {
        throw std::runtime_error("Empty data vector");
    }

    int amount = data.size() - 1;
    double avg_value = Get_Avg_Sensor_value(data);
    double variance = 0.0;

    for(auto s = data.begin() + 1; s != data.end(); ++s){
        variance = variance + std::pow((std::stod(s->second) - avg_value), 2);
    }

    return variance / amount;
}

double Analysing::Get_Range_value(std::vector<std::pair<std::string, std::string> > &data){
    return Get_Max_Sensor_value(data) - Get_Min_Sensor_value(data);
}