#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>

int main() {
    std::fstream fs;
    std::fstream f;
    std::vector<std::string> v;
    int size = 0;
    fs.open("romeoandjuliet.txt", std::ios::in);
    if (fs.is_open())
    {
        std::string buf;
        while (!fs.eof())
        {
            getline(fs, buf);
            size++;
        }
        //cout << size << endl;
        v.resize(size);
        fs.seekg(0, std::ios::beg);
        for (int i = 0; i < size; ++i)
        {
            getline(fs, v[i]);
        }
        f.open("romeoandjuliet_out.txt", std::ios::out);
        if (f.is_open())
        {
            for (int i = 1; i <= v.size(); ++i) {
                f << i << " " << v[i] << std::endl;
            }
            f.close();
        }
        else
            std::cerr << "Error opening output file" << std::endl;
        fs.close();
    }
    else
        std::cerr << "Error opening input file" << std::endl;
}


