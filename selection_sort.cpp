#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

const string filename = "instancias-num/num.100000.4.in"; // alterar

int main() {
    
    ifstream inFile(filename);
    
    vector<int> data;
    int num;

    while (inFile >> num) {
        data.push_back(num);
    }
    inFile.close();

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < data.size() - 1; ++i) {
        int aux = i;
        for (int j = i + 1; j < data.size(); ++j) {
            if (data[j] < data[aux]) {
                aux = j;
            }
        }
        swap(data[i], data[aux]);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Salvar
    ofstream outFile("resultados.txt", ios::app);
    outFile << "selectionSort: " << duration.count() << " segundos\n\n";
    outFile.close();

    return 0;
}
