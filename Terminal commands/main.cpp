#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <dirent.h>


using namespace std;



int help()
{

    cout << "\n \n\n**********************\nLista de comandos: \n \ngot init <name> \nInstancia un nuevo repositorio en el servidor" << endl ;
    cout << "\n \ngot add [-A][name] \nPermite agregar todos lo archivos" << endl ;
    cout << "\n \ngot commit <mensaje> \nEnvia los archivos agregados y pendientes de commit al server" << endl ;
    cout << "\n \ngot status <file> \nMuestra cuales archivos han sido cambiados" << endl ;
    cout << "\n \ngot rollback <file> <commit>\nPermite regressar un archivo en el tiempo a un commit especifico" << endl ;
    cout << "\n \ngot reset <file>\nDeshace cambios locales para un archivo y lo regresa al ultimo commit" << endl ;
    cout << "\n \ngot sync <file>\nRecupera los cambios para un archivo en el server y lo sincroniza con el archivo en el cliente\n**********************\n \n" << endl ;


    return 0;

}

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




int init()
{

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


int main()
{
    
    string comand;

    getline(cin,comand);

    //cout << "\nEl comando es: " << comand << endl ;


    if (comand == "got init"){

        init();
        main();
    }

    if (comand == "got help"){

        help();
        main();

    }

    else {

        cout << "\nEl comando no existe" << endl ;
        cout << "\ngot help para ver lista de comandos\n \n" << endl ;



        main();
    }


    return 0;
}