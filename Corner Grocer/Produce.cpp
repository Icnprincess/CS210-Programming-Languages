#include "Produce.h"

// Produce class implementations
Produce::Produce(const string& filename)
    : filename(filename) {
}

//Read file into program
void Produce::processFile() {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not open the file " + filename);
    }
    string item;
    while (file >> item) {
        itemFrequency[normalizeItem(item)]++;
    }
    file.close();
}

//backup and save data
void Produce::backupData(const string& backupFilename) const {
    ofstream backupFile(backupFilename);
    if (!backupFile.is_open()) {       
        throw runtime_error("Error: Could not create backup file " + backupFilename);
    }
    for (const auto& pair : itemFrequency) {
        backupFile << pair.first << " " << pair.second << "\n";
    }
    backupFile.close();
}

//normalize data so that it is all treated the same
string Produce::normalizeItem(string item) const {
    transform(item.begin(), item.end(), item.begin(),
        [](unsigned char c) { return tolower(c); });
    return item;
}

void Produce::printFrequencyList() const {
    cout << "\n--- Purchase Frequency List ---\n";
    for (const auto& pair : itemFrequency) {
        string capitalizedItem = pair.first;
        if (!capitalizedItem.empty()) {
            capitalizedItem[0] = toupper(capitalizedItem[0]);
        }
        cout << capitalizedItem << " " << pair.second << "\n";
    }
}

void Produce::printHistogram() const {
    cout << "\n--- Purchase Frequency Histogram ---\n";
    for (const auto& pair : itemFrequency) {
        string capitalizedItem = pair.first;
        if (!capitalizedItem.empty()) {
            capitalizedItem[0] = toupper(capitalizedItem[0]);
        }
        cout << capitalizedItem << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << "\n";
    }
}

int Produce::findItemFrequency(const string& item) const {
    string normalizedItem = normalizeItem(item);
    auto it = itemFrequency.find(normalizedItem);
    if (it != itemFrequency.end()) {
        return it->second;
    }
    return 0;
}

// MenuHandler class implementations
MenuHandler::MenuHandler(Produce& tracker)
    : tracker(tracker) {
}

void MenuHandler::displayMenu() const {
    cout << "\nCorner Grocer Analysis Menu\n";
    cout << "1: Find an item's purchase frequency\n";
    cout << "2: Print all item frequencies\n";
    cout << "3: Print item frequency histogram\n";
    cout << "4: Exit\n";
    cout << "Enter your choice (1-4): ";
}

void MenuHandler::handleChoice(int choice) {
    switch (choice) {
    case 1: {
        string itemToFind;
        cout << "\nEnter the item you want to find: ";
        cin >> itemToFind;
        int frequency = tracker.findItemFrequency(itemToFind);
        if (frequency > 0) {
            if (!itemToFind.empty()) {
                itemToFind[0] = toupper(itemToFind[0]);
            }
            cout << "\n" << itemToFind << " was purchased " << frequency << " time(s).\n";
        }
        else {
            cout << "\nItem not found.\n";
        }
        break;
    }
    case 2:
        tracker.printFrequencyList();
        break;
    case 3:
        tracker.printHistogram();
        break;
    case 4:
        cout << "Exiting program. Goodbye!\n";
        break;
    default:
        cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        break;
    }
}

void MenuHandler::run() {
    int choice = 0;
    while (choice != 4) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        handleChoice(choice);
    }
}
