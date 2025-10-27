/* 
Corner Grocer.cpp : This file contains the 'main' function.
Isis Jackson
*/

#include "Produce.h"

int main() {
    const string filename = "CS210_Project_Three_Input_File.txt";
    const string backupFilename = "frequency.dat";

    try {
        Produce produceTracker(filename);
        produceTracker.processFile();
        produceTracker.backupData(backupFilename);

        MenuHandler menu(produceTracker);
        menu.run();
    }
    catch (const runtime_error& e) {
        cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}

