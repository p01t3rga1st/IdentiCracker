#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Funkcja do generowania kombinacji hasła
void generateCombinations(vector<string>& combinations) {
    for (char c1 : {'L', 'M', 'R'}) {
        for (char c2 : {'L', 'M', 'R'}) {
            for (char c3 : {'L', 'M', 'R'}) {
                for (char c4 : {'L', 'M', 'R'}) {
                    for (char c5 : {'L', 'M', 'R'}) {
                        for (char c6 : {'L', 'M', 'R'}) {
                            for (char c7 : {'L', 'M', 'R'}) {
                                combinations.push_back(string(1, c1) + c2 + c3 + c4 + c5 + c6 + c7);
                            }
                        }
                    }
                }
            }
        }
    }
}

// Funkcja do zapisywania historii kombinacji do pliku
void saveCombinationsToFile(const vector<string>& combinations, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const string& combination : combinations) {
            outputFile << combination << endl;
        }
        outputFile.close();
    } else {
        cout << "Unable to open file for writing!" << endl;
    }
}

int main() {
    vector<string> combinations;
    vector<string> acceptedCombinations;
    size_t lastPosition = 0;

    generateCombinations(combinations);
    size_t totalCombinations = combinations.size();

    for (size_t i = 0; i < combinations.size(); ++i) {
        const string& combination = combinations[i];
        double percentCompleted = 100.0 * (i + 1) / totalCombinations;
        cout << "Combination " << i + 1 << "/" << totalCombinations << " (" << percentCompleted << "%): " << combination << endl;
        cout << "Accept (y/n)? ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            acceptedCombinations.push_back(combination);
        }
        // Zapisz aktualną listę zaakceptowanych kombinacji do pliku
        saveCombinationsToFile(acceptedCombinations, "accepted_combinations.txt");
        ++lastPosition;
    }

    cout << "Accepted combinations saved to 'accepted_combinations.txt'" << endl;

    return 0;
}
