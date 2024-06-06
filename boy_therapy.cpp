#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

bool fileExists(const std::string&filename) {
    ifstream infile(filename);
    return infile.good();
}

void writeLog(string whatsup, string whatdo){
    time_t now = std::time(nullptr);
    tm* localTime = std::localtime(&now); 
    stringstream filename;
    filename << put_time(localTime, "%d-%m-%y-%H-%M-%S") << ".txt";
    ofstream outfile(filename.str()); 
    outfile << "whats up: " << whatsup << endl;
    outfile << "what to do: " << whatdo << endl;
    outfile.close();
    std::cout << "(conversation written to " << filename.str() << ")" << std::endl;
}

int main(){
    cout << "Boy Therapy v0.1 by Kunal Shandilya" << endl;
    cout << "Downloading model weights from BroNet..." << endl;


    if(!fileExists("boytherapy_model_weights.txt")){
        string x = "man up "; 
        int n = 69;
        ofstream outfile("boytherapy_model_weights.txt");
        string repeatedX;
        repeatedX.reserve(x.size() * n); // Preallocate for efficiency
        for (int i = 0; i < n; ++i) {
            repeatedX += x;
        }
        outfile << repeatedX;
        outfile.close();
        this_thread::sleep_for(chrono::seconds(10));
        cout << "Model weights downloaded to boytherapy_model_weights.txt" << endl;
    }
    cout << "Initiating call to Boy... (loading model)" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << " Boy: sup, all good? (y/n)" << endl;
    string response;
    getline(cin, response);
    if (response == "n"){
        cout << " Boy: whats up" << endl;
        string whatsup;
        getline(cin, whatsup);
        cout << " Boy: damn, thats crazy. so what will you do" << endl;
        string whatdo;
        getline(cin, whatdo);
        writeLog(whatsup, whatdo);
    }
    cout << " Boy: sounds good. ttyl" << endl;
    cout << "Boy disconnected. Press any key to exit...";
    getline(cin,response);
    return 0;
}