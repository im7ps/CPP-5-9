#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "Vector.hpp"
#include "Deque.hpp"


int doSort(std::vector<int> array, std::deque<int> myDeque)
{
    if (array.empty() || myDeque.empty())
        return(1);
    std::cout << std::endl;
    std::vector<int>::size_type i = 0;
    std::cout << "Array non ordinato: ";
    while(i < array.size())
    {
        std::cout << array[i] << " ";
        i++;
    }
   
    std::cout << std::endl;
    i = 0;
    std::cout << "Deque non ordinato: ";
    while(i < array.size())
    {
      std::cout << myDeque[i] << " ";
        i++;
    }
    std::cout << std::endl;

    // Ordina l'array utilizzando merge-insertion sort
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedArray = mergeInsertionSort(array);
    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << std::endl;
    std::chrono::high_resolution_clock::time_point startTime2 = std::chrono::high_resolution_clock::now();
    std::deque<int> sortedDeque = mergeInsertionSort2(myDeque);
    std::chrono::high_resolution_clock::time_point endTime2 = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration2 = std::chrono::duration_cast<std::chrono::microseconds>(endTime2 - startTime2);
    
    std::cout << "Array ordinato: ";
    i = 0;
    while(i < array.size())
    {
        std::cout << sortedArray[i] << " ";
        i++;
    }
    std::cout << std::endl;
    i = 0;
    std::cout << "Deque ordinato: ";
    while(i < array.size())
    {
        std::cout << sortedDeque[i] << " ";
        i++;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Conteiner = Vector, " << "Tempo impiegato: " << duration.count() << " microsecondi" << std::endl;
    std::cout << "Conteiner = Deque, " << "Tempo impiegato: " << duration2.count() << " microsecondi" << std::endl;
    std::cout << std::endl;
    return(0);
}


std::deque<int> fillContDeque(std::string risultato)
{
    int i = 0;
    std::vector<int> values;
    std::string currentNumber;
    std::deque<int> myDeque;
    while(risultato[i])
    {
        if (risultato[i] != 32)
            currentNumber += risultato[i];
        else
        {
            if(!currentNumber.empty())
            {
                try
                {
                    int number = std::stoi(currentNumber);
                    values.push_back(number);
                    currentNumber.clear();
                } catch(const std::exception& e){
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }
        }
        i++;
    }
    if(!currentNumber.empty())
    {
        try
        {
            int number = std::stoi(currentNumber);
            values.push_back(number);
        } catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    for (std::vector<int>::size_type j = 0; j < values.size(); j++)
    {
            myDeque.push_back(values[j]);
    }
    return(myDeque);
    
}

std::vector<int> fillContVec(std::string risultato)
{
    int i = 0;
    std::vector<int> values;
    std::string currentNumber;
    std::vector<int> array;
    while(risultato[i])
    {
        if (risultato[i] != 32)
            currentNumber += risultato[i];
        else
        {
            if(!currentNumber.empty())
            {
                try
                {
                    int number = std::stoi(currentNumber);
                    values.push_back(number);
                    currentNumber.clear();
                } catch(const std::exception& e){
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }
        }
        i++;
    }
    if(!currentNumber.empty())
    {
        try
        {
            int number = std::stoi(currentNumber);
            values.push_back(number);
        } catch(const std::exception& e){
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    for (std::vector<int>::size_type j = 0; j < values.size(); j++)
    {
            array.push_back(values[j]);
    }
    return (array);
}

void doCommand (std::string comando){
    char risultato[1024];
    FILE* pipe = popen(comando.c_str(), "r");
    if (pipe) {
        while (!feof(pipe) && !ferror(pipe)) {
            if (fgets(risultato, sizeof(risultato), pipe) != nullptr) {
                // Elabora il risultato come desiderato
               // std::cout << risultato;
            }
        }
    if(doSort(fillContVec(risultato),fillContDeque(risultato)) == 1)
        {
            std::cout << "Argument error"<< std::endl;
            return ;
        }
    pclose(pipe);
    }
}

int checkArgv(std::string valore)
{
    int i = 0;
    while(valore[i])
    {
        if (!isnumber(valore[i]))
        {
            if (valore[i] == 32)
            {
                i++;
                continue;
            }
            std::cout << "i valori devono essere interi" << std::endl;
            return (1);
        }
        i++;
    }
    return (0);
}

int main(int argc, char **argv) {

    if (argc != 2)
    {
        std::cout << "Error 1" << std::endl;
        return (1);
    }
    std::string valore = argv[1];
    std::string command = "jot";
    size_t pos = valore.find(command);
    if(pos != std::string::npos)
    {
        doCommand(argv[1]);
        return(0);
    }
    else
    {
        if (checkArgv(valore) == 1)
            return (1);
        if(doSort(fillContVec(valore),fillContDeque(valore)) == 1)
        {
            std::cout << "Argument error"<< std::endl;
            return (1);
        }
    }
    
    return 0;
}