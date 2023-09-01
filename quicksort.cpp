#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;

#define SCREEN_CLEANER cout<<"\033[2J\033[3J\033[H\033[48;2;25;22;34m";
#define START_LINE "\033[100D"
#define RED "\033[2K\033[38;2;233;99;121m\033[48;2;25;22;34m" START_LINE
#define YELLOW "\033[2K\033[38;2;231;222;121m\033[48;2;25;22;34m" START_LINE
#define WHITE "\033[2K\033[38;2;255;255;255m\033[48;2;25;22;34m" START_LINE
#define BLUE "\033[2K\033[38;2;98;175;255m\033[48;2;25;22;34m" START_LINE
#define PINK "\033[2K\033[38;2;255;121;198m\033[48;2;25;22;34m" START_LINE
#define GREEN "\033[2K\033[38;2;103;228;128m\033[48;2;25;22;34m" START_LINE


void sort(vector<string>*);
void quicksort(vector<string>*, int, int);
void printLine(vector<string>*, int, string, int);

int main(){
    SCREEN_CLEANER
    
    ifstream file("sort.txt");      
    if(!file.is_open()){
        cerr << "Unable to find a sort.txt file" << endl;
        return 1;
    }   

    string line;
    vector<string> names;

    while(getline(file, line) && line != ""){
        names.push_back(line);
    }

    cout << endl;
    for (string name : names){
        cout << WHITE << name << endl;
    }

    int end = names.size() - 1;
    quicksort(&names, 0, end);
    cout << endl;

    file.close();
    return 0;
}

void quicksort(vector<string>* names, int start, int end){
    int i = start;
    int j = end;
    string aux;
    int mid = (start + end) / 2;
    string pivot = (*names)[mid];
    
    while (i <= j){
        printLine(names, mid, RED, 150);

        while ((*names)[i] < pivot){  
            printLine(names, i, YELLOW, 100);
            printLine(names, i, WHITE, 200);
            i++;
        }
        while ((*names)[j] > pivot){
            printLine(names, j, BLUE, 100);
            printLine(names, j, WHITE, 200);
            j--;
        }
        if (i <= j){
            printLine(names, i, PINK, 0);
            printLine(names, j, GREEN, 0);
            sleep_for(chrono::milliseconds(600));

            aux = (*names)[i];
            (*names)[i] = (*names)[j];
            (*names)[j] = aux;

            printLine(names, i, PINK, 0);
            printLine(names, j, GREEN, 0);

            sleep_for(chrono::milliseconds(200));

            printLine(names, i, WHITE, 0);
            printLine(names, j, WHITE, 0);

            sleep_for(chrono::milliseconds(300));
            i++;
            j--;
        } 
    }
    sleep_for(chrono::milliseconds(150));

    printLine(names, mid, RED, 0);
    printLine(names, (i + 1), PINK, 0);
    printLine(names, end, GREEN, 0);

    sleep_for(chrono::milliseconds(150));


    printLine(names, mid, WHITE, 0);
    printLine(names, (i + 1), WHITE, 0);
    printLine(names, end, WHITE, 0);

    if (start < j){
        quicksort(names, start, j);
    }
    if (i < end){
        quicksort(names, i, end);
    }
}

void printLine(vector<string>* names, int line, string color, int delay){
    sleep_for(chrono::milliseconds(delay));
    cout << "\033[" << (line + 1) << ";100H" << color << (*names)[line]; cout.flush();
}