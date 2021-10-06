#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int except(string text){
    cerr << text << endl;
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc < 3) return except("Usage: xor file1 file2 [fileN] > output-file");

    int filesCount = argc-1;

    ifstream files[argc];

    for(int i = 0; i < filesCount; i++){
        files[i].open(argv[i+1], ios::in | ios::binary);
        if(!files[i].is_open()){
            return except("Cant open file");
        }
        files[i].seekg(0, ios::beg);
    }

    char buffer[1];
    char output = 0;
    bool inWork = true;

    while(inWork){
        for(int i=0; i < filesCount; i++){
            files[i].read(buffer, 1);
            int readCount = files[i].gcount();
            if(readCount == 0){
                inWork = false; break;
            }
            output ^= buffer[0];
        }

        if(inWork){
            cout << output;
        }
        output = 0;
    }

    for(int i=0; i < filesCount; i++){
        files[i].close();
    }

    return 0;
}