#ifndef ANALYZER_H
#define ANALYZER_H

#include <vector>
#include <string>

class Analysing{
    public:
        double Get_Duration(std::vector<std::pair<std::string, std::string> > &data);
        double Get_Max_Sensor_value(std::vector<std::pair<std::string, std::string> > &data);
        double Get_Min_Sensor_value(std::vector<std::pair<std::string, std::string> > &data);
        double Get_Avg_Sensor_value(std::vector<std::pair<std::string, std::string> > &data);
        double Get_Variance_value(std::vector<std::pair<std::string, std::string> > &data);
        double Get_Range_value(std::vector<std::pair<std::string, std::string> > &data);
};


#endif