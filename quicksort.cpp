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


void sort(vector<string>&);
void quicksort(vector<string>&, int, int);
int partition(vector<string>&,int, int);

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
    quicksort(names, 0, end);
    cout << endl;

    file.close();
    return 0;
}

void quicksort(vector<string>& names, int start, int end){
    int i = start;
    int j = end;
    string aux;
    int mid = (start + end) / 2;
    string pivot = names[mid];
    
    while (i <= j){
        sleep_for(chrono::milliseconds(150));
        cout << "\033[" << (mid + 2) << ";100H" RED << pivot; cout.flush();

        while (names[i] < pivot){  
            sleep_for(chrono::milliseconds(100));
            cout << "\033[" << (i + 2) << ";100H" YELLOW << names[i]; cout.flush();

            sleep_for(chrono::milliseconds(200));
            cout << "\033[" << (i + 2) << ";100H" WHITE << names[i]; cout.flush();

            i++;
        }
        while (names[j] > pivot){
            sleep_for(chrono::milliseconds(100));
            cout << "\033[" << (j + 2) << ";100H" BLUE << names[j]; cout.flush();

            sleep_for(chrono::milliseconds(200));
            cout << "\033[" << (j + 2) << ";100H" WHITE << names[j]; cout.flush();

            j--;
        }
        if (i <= j){
            cout << "\033[" << (i + 2) << ";100H" PINK << names[i]; cout.flush();
            cout << "\033[" << (j + 2) << ";100H" GREEN << names[j]; cout.flush();
            sleep_for(chrono::milliseconds(600));

            aux = names[i];
            names[i] = names[j];
            names[j] = aux;

            cout << "\033[" << (i + 2) << ";100H" PINK << names[i]; cout.flush();
            cout << "\033[" << (j + 2) << ";100H" GREEN << names[j]; cout.flush();

            sleep_for(chrono::milliseconds(200));

            cout << "\033[" << (i + 2) << ";100H" WHITE << names[i];
            cout << "\033[" << (j + 2) << ";100H" WHITE << names[j];

            sleep_for(chrono::milliseconds(300));
            i++;
            j--;
        } 
    }
    sleep_for(chrono::milliseconds(150));

    cout << "\033[" << (mid + 2) << ";100H" RED << names[mid]; cout.flush();
    cout << "\033[" << (i + 1 + 2) << ";100H" PINK << names[i + 1]; cout.flush();
    cout << "\033[" << (end + 2) << ";100H" GREEN << names[end]; cout.flush();

    sleep_for(chrono::milliseconds(150));

    cout << "\033[" << (mid + 2) << ";100H" WHITE << names[mid]; cout.flush();
    cout << "\033[" << (i + 1 + 2) << ";100H" WHITE << names[i + 1]; cout.flush();
    cout << "\033[" << (end + 2) << ";100H" WHITE << names[end]; cout.flush();

    if (start < j){
        quicksort(names, start, j);
    }
    if (i < end){
        quicksort(names, i, end);
    }
}
