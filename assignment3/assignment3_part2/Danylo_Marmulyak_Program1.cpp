#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;
// func, which simply  prints out all el from array to file
void f_writeSubarray(ofstream& file, const vector<int> &B){
    for(auto el: B){
        file << el;
    }
    file << '\n';
}

// func, which creating all subarrays and writes it to file
void f_generateSubarray(int n, const string& filename){
    ofstream file(filename);
    
    if(!file.is_open()){
        cerr << "Blad przy otworzeniu pliku" <<  endl;
        return;
    }
    vector<int> B(n, 0);
    //value of el in array for now
    int i = 0;
    while(true){
        f_writeSubarray(file, B);
        i++;
        int p = 1;
        int j = i;
        while(j % 2 ==0){
            j = j / 2;
            p++; 
        }
        if(p <= n){
            B[p - 1] = 1 - B[p - 1];
        }else
            break;
    }
    file.close();
}



int main(){
    int n;
    string filename;
    cout << "Write the num of elements in array: " << endl;
    cin >> n;

    cout << "Write the nameof the file program will create: " << endl;
    cin >> filename;

    if(n <= 0){
        cerr << "N must be positive";
        return 1;
    }
    f_generateSubarray(n, filename);

    return 0;
}