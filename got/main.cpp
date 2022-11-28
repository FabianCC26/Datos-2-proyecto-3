#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <dirent.h>


using namespace std;



int help()
{

    cout << "\n \n\n**********************\nLista de comandos: \n \ngot init <name> \nInstancia un nuevo repositorio en el servidor" << endl ;
    cout << "\n \ngot add [name] \nPermite agregar todos lo archivos" << endl ;
    cout << "\n \ngot commit <mensaje> \nEnvia los archivos agregados y pendientes de commit al server" << endl ;
    cout << "\n \ngot status .\nMuestra cuales archivos han sido modificados" << endl ;
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

    cout << "\nSe puede dar seguimiento a:\n" << endl;

    while (entity != NULL)
    {
        if (entity->d_type == 8){

            string var = entity->d_name;

        
            if(var != "app" && var != "main.cpp"){

                printf("%s\n", entity->d_name);

            }

            
        }
        
        entity = readdir(dir);
    }

    cout << endl;
    
    closedir(dir);



}


int add(string fileName){


    fstream myFile;

    fstream myFile2;



    myFile.open(fileName,ios::in);


    string newName;


    newName.append("got/");
    newName.append(fileName);


    myFile2.open(newName,ios::out);


    if(myFile.is_open()){

        string line;

       while (getline(myFile, line))
       {


            myFile2 << line << endl;

            
       }
       

        myFile.close();


    }


    cout << endl;


    return 0;


}



int init(string fileName)
{


    string initName;


    initName.append("mkdir -p ");
    initName.append(fileName);



    system(initName.data());


    fstream myFile;

    
    fileName.append("/.gotignore");

    myFile.open(fileName,ios::out);


    if(myFile.is_open()){



        myFile << "app" << "\nmain.cpp" << endl;

        
        myFile.close();


    }



    listFiles(".");


    return 0;


}



int status(){


    DIR* dir = opendir("/home/fabian/Desktop/Proyectos/Datos 2/Proyecto 3/got/got");

    if (dir == NULL){
        return 1;
    }

    struct dirent* entity;

    entity = readdir(dir);

    cout << "\nArchivos modificados recientemente:\n" << endl;

    while (entity != NULL)
    {
        if (entity->d_type == 8){

            printf("%s\n", entity->d_name);

            
        }
        
        entity = readdir(dir);
    }

    cout << endl;
    
    closedir(dir);

    return 0;

}

int reset(string fileName){


    fstream myFile;

    fstream myFile2;



    myFile.open(fileName,ios::out);


    string newName;


    newName.append("got/");
    newName.append(fileName);


    myFile2.open(newName,ios::in);


    if(myFile2.is_open()){

        string line;

       while (getline(myFile2, line))

       {


            myFile << line << endl;

            
       }
       

        myFile.close();
        myFile2.close();


    }


    cout << endl;


    return 0;


}





int main()
{
    
   
    string comand;
    string comand2;
    string comand3;


    cin >> comand;
    
    cin >> comand2;
    
    cin >> comand3;
    
    

    if (comand == "got" && comand2 == "init"){

        init(comand3);
        main();
    }

    if (comand == "got" && comand2 == "help" && comand3 == "."){

        help();
        main();

    }

    if (comand == "got" && comand2 == "add"){

        add(comand3);
        main();


    }

    if (comand == "got" && comand2 == "status"){

        status();
        main();


    }

    if (comand == "got" && comand2 == "status"){

        status();
        main();


    }

    if (comand == "got" && comand2 == "reset"){

        reset(comand3);
        main();


    }

    else {

        cout << "\nEl comando no existe" << endl ;
        cout << "\n'got help .'para ver lista de comandos\n \n" << endl ;



        main();
    }


    return 0;
}