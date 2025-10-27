#pragma once
#ifndef PRODUCE_H
#define PRODUCE_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
using namespace std;

class Produce {
public:
    Produce(const string& filename);
    void processFile();
    void printFrequencyList() const;
    void printHistogram() const;
    int findItemFrequency(const string& item) const;
    void backupData(const string& backupFilename) const; // New method


private:
    string filename;
    map<string, int> itemFrequency;
    string normalizeItem(string item) const;
};

class MenuHandler {
public:
    MenuHandler(Produce& tracker);
    void run();

private:
    void displayMenu() const;
    void handleChoice(int choice);
    Produce& tracker;
};

#endif