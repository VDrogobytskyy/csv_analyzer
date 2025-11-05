#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
#include "vector"


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

    while(std::getline(file, line)){
        std::stringstream s_line(line);
        s_line >> time_line;

        std::getline(s_line, sensor_line);

        std::pair<std::string, std::string> temp_res(time_line, sensor_line);
        collected_data.push_back(temp_res);

        s_line.clear();
        sensor_line.clear();
        line.clear();
    }

    for(std::pair<std::string, std::string> pairs : collected_data){
        std::cout << pairs.first << " " << pairs.second << std:: endl;
    }


    file.close();
    std::cout << std::endl;
    return 0;
}