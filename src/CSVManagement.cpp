//
// Created by einat on 02/08/2022.
//
#include "CSVManagement.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace Geometry;
using namespace CSV;
using namespace std;


CSVManagement::CSVManagement(const string &classifiedDataPath, const string &unclassifiedDataPath,
                             const string &fileOutputPath) {
    _classifiedDataPath = classifiedDataPath;
    _unclassifiedDataPath = unclassifiedDataPath;
    _fileOutputPath = fileOutputPath;
    createClassifiedData();
    createUnclassifiedData();
}

vector<vector<string>> CSVManagement::createDataVector(const string &filePath) {
    vector<vector<string>> data;
    vector<string> row;
    string line, word;

    fstream file(filePath, ios::in);
    if (file.is_open()) {
        // create data string vectors from the given classified.csv file
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            data.push_back(row);
        }
    } else {
        cout << "Could not open the file" << endl;
    }
    return data;
}

void CSVManagement::createClassifiedData() {
    vector<vector<string>> data = createDataVector(_classifiedDataPath);
    // create the data field using the data vectors created above
    vector<Point> setosa;
    vector<Point> versicolor;
    vector<Point> virginica;
    for (auto &i: data) {
        // iris coordinates
        Point valus({stod(i[0]), stod(i[1]), stod(i[2]),
                     stod(i[3])});
        if (i[4].find("setosa") != string::npos) {
            setosa.push_back(valus);
        } else if (i[4].find("versicolor") != string::npos) {
            versicolor.push_back(valus);
        }
            //  last option (assuming the input file is valid): data[i][4].find("virginica") != string::npos
        else {
            virginica.push_back(valus);
        }
    }
    _classifiedData.push_back(setosa);
    _classifiedData.push_back(versicolor);
    _classifiedData.push_back(virginica);
}

void CSVManagement::createUnclassifiedData() {
    vector<vector<string>> data = createDataVector(_unclassifiedDataPath);
    for (auto &i: data) {
        _unclassifiedData.push_back(Point({stod(i[0]), stod(i[1]), stod(i[2]),
                                           stod(i[3])}));
    }
}

void CSVManagement::createCSVOutputFile(const vector<string> &classifiedData, const string &fileOutputName) {
    ofstream writingFile(_fileOutputPath + fileOutputName);
    for (const auto &i: classifiedData) {
        writingFile << i << endl;
    }
    writingFile.close();
}

vector<vector<Geometry::Point>> CSVManagement::getClassifiedData() {
    return _classifiedData;
}

vector<Geometry::Point> CSVManagement::getUnclassifiedData() {
    return _unclassifiedData;
}