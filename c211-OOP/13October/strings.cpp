#include <iostream>
using namespace std;

class  String {
    char * data;
    int size;

public:
    String()
    {
        data = nullptr;
        size = 0;
    }

    String( char c)
    {
        size =2;
        data =  new char[size];
        data[0] = c;
        data [1] = '\0';
    }
    String(const char * str)
    {
        int len = 0;
        while(str[len] != '\0'){
            len++;
        }
        size = len +1;

        data = new char[size];

        for (int i=0; i<size; i++) {

            data[i] = str[i];
        }
        
    }

    ~String(){
        delete[] data;
        data = nullptr;
    }
    // taking input from console in *this object
    void input()
    {
        char buffer[1000];
        cin.getline(buffer, 1000);
        int len = 0;
        while(buffer[len] != '\0'){
            len++;
        }
        size = len +1;

        delete[] data;
        data = new char[size];

        for (int i=0; i<size; i++) {

            data[i] = buffer[i];
        }
    }
    char & at(int index){
        // receive index of string and return reference of array location represented by index
        if (index >= 0 && index < size) {
            return data[index];
        }
        // If index is out of bounds, return the first element
        return data[0];
    }
    bool isEmpty(){
        return size == 0;
    }
    int getLength(){
        return size - 1;
    }
    int getSize(){
        return size;
    }
};