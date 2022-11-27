#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <dirent.h>


using namespace std;



void listFiles(const char* dirname){

    DIR* dir = opendir(dirname);

    if (dir == NULL){
        return;
    }

    struct dirent* entity;

    entity = readdir(dir);

    while (entity != NULL)
    {
        if (entity->d_type == 8){

            printf("%s\n", entity->d_name);
        }
        
        entity = readdir(dir);
    }
    
    closedir(dir);



}

int main(){

    
    listFiles(".");
    
    system("mkdir -p test");


    fstream myFile;

    fstream myFile2;



    myFile.open("Otest.txt",ios::in);

    myFile2.open("test/Ctest.txt",ios::out);


    if(myFile.is_open()){

        string line;

       while (getline(myFile, line))
       {


            myFile2 << line << endl;

            //cout << line << endl;
       }
       

        myFile.close();


    }


    return 0;

}