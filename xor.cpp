#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int except(string text){
    cerr << text << endl;
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc < 3) return except("Usage: xor [-i] file1 [fileN] > output-file\nThe resulting output will be the same size as the shortest file");
    
	int mode = 0; // Default mode - using only files
	
	int filesCount = 0;
	if(strcmp(argv[1], "-i") == 0){
		filesCount = argc-2;
		mode = 1; // Using both files and stdin
	} else {
		filesCount = argc-1;
	} 
	
    ifstream files[filesCount+1];

    int i; // Iterator variable
    for(i = 0; i < filesCount; i++){
        files[i].open(argv[i+(argc - filesCount)], ios::in | ios::binary);
        if(!files[i].is_open()){
            return except("Can't open file"); // Add filename
        }
    }

    char buffer[1];
    char output = 0;
    bool inWork = true;

    int readCount = 0; // Read counter
    while(inWork){
        for(i=0; i < filesCount; i++){
            files[i].read(buffer, 1);
            readCount = files[i].gcount();
            if(readCount == 0){
                inWork = false; break;
            }
            output ^= buffer[0];
        }
		
		if(mode == 1){
			cin.read(buffer, 1);
			readCount = cin.gcount();
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