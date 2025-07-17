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
    
    for (int i = 1; i < data.size(); ++i) {
        int aux = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > aux) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = aux;
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    
    // Salvar
    ofstream outFile("resultados.txt", ios::app);
    
    outFile << "Arquivo " << filename << ":\n";
    outFile << "insertionSort: " << duration.count() << " segundos\n";
    outFile.close();
    
    return 0;
}
