#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Analyzer.h"


int main(int argc, char* argv[]){
    std::cout << std::endl;

    std::vector<std::pair<std::string, std::string> > collected_data;
    std::string line, time_line, sensor_line;
    

    if(argc < 2){
        std::cerr << "There must be a .csv file when compile." << std::endl;
    }

    std::string file_name = argv[1];

    std::ifstream file(file_name);

    if(!file){
        std::cerr << "File was not opened." << std::endl;
    }

    std::string sensor_name;
    if (std::getline(file, line)) { 
        std::stringstream ss(line);
        std::string dummy;
        std::getline(ss, dummy, ',');        
        std::getline(ss, sensor_name, ',');  
    }

    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string time_line, value_line;

        std::getline(ss, time_line, ',');   
        std::getline(ss, value_line, ',');  

        collected_data.emplace_back(time_line, value_line);
        time_line.clear();
        value_line.clear();
    }

    Analysing analysis;

    std::cout << "We are using sensor: " << sensor_name << std::endl;

    std::cout << "Duration(in mili-seconds): " << analysis.Get_Duration(collected_data) << std::endl;
    std::cout << "Max value from sensor: " << analysis.Get_Max_Sensor_value(collected_data) << std::endl;
    std::cout << "Min value from sensor: " << analysis.Get_Min_Sensor_value(collected_data) << std::endl;
    std::cout << "Avg value from sensor: " << analysis.Get_Avg_Sensor_value(collected_data) << std::endl;
    std::cout << "Variance: " << analysis.Get_Variance_value(collected_data) << std::endl;
    std::cout << "Rang(difference between max and min value ): " << analysis.Get_Range_value(collected_data) << std::endl;

    file.close();

    std::cout << std::endl;
    std::cout << "This is all collected data from file: " << file_name << std::endl;

    std::cout << std::endl;
    return 0;
}