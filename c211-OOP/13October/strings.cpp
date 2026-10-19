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
    void display(){
        for (int i = 0; i< size; i++){
            cout<<data[i];
        }
    }
    int find(String subStr, int start = 0) {
    int i = start;
    
    // Loop through the main string until the end
    while (data[i] != '\0') {
        int j = 0;
        /* LOGIC IS HARD FR..... but not that hard i can do this..[twinkle][twinkle][twinkle]*/
        // Check if characters match sequentially
        while (subStr.data[j] != '\0' && data[i + j] == subStr.data[j]) {
            j++;
        }
        
        // If we reached the end of subStr, it means we found a full match!
        if (subStr.data[j] == '\0') {
            return i;
        }
        
        i++;
    }
    
    // Return -1 if not found
    return -1;
}
    void insert(int index, String subStr){
        
        if(index < 0 || index > getLength()){
            cout<<"Index out of bounds"<<endl;
            return;
        }
        int newSize = size + subStr.size - 1; // -1 because both strings have null terminator
        char * newData = new char[newSize];

        // Copy characters from the original string up to the insertion index
        for (int i = 0; i < index; i++) {
            newData[i] = data[i];
        }

        // Copy characters from the substring
        for (int j = 0; j < subStr.size - 1; j++) { // -1 to avoid copying the null terminator
            newData[index + j] = subStr.data[j];
        }

        // Copy the remaining characters from the original string after the insertion index
        for (int k = index; k < size - 1; k++) { // -1 to avoid copying the null terminator
            newData[subStr.size - 1 + k] = data[k];
        }

        newData[newSize - 1] = '\0'; // Add null terminator at the end

        delete[] data; // Free old memory
        data = newData; // Update data pointer
        size = newSize; // Update size
        
    }
    void remove(int index, int count = 1) {
    int len = (size > 0) ? size - 1 : 0;

    // Bounds check: if index is invalid or string is empty, do nothing
    if (index < 0 || index >= len || len == 0) {
        return;
    }

    // If the removal covers everything from index to the end (or beyond)
    if (index == 0 && count >= len) {
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }

    // Adjust count if it exceeds the remaining characters
    int removeCount = count;
    if (index + count > len) {
        removeCount = len - index;
    }

    int newLen = len - removeCount;
    int newSize = newLen + 1;

    // 1. Allocate new memory on the heap
    char *newData = new char[newSize];
    int k = 0;

    // 2. Copy the part of the string BEFORE the removal index
    for (int i = 0; i < index; i++) {
        newData[k++] = data[i];
    }

    // 3. Skip the removed characters and copy the part AFTER the removal section
    for (int i = index + removeCount; i < len; i++) {
        newData[k++] = data[i];
    }

    // 4. Add the null terminator
    newData[k] = '\0';

    // 5. Clean up old memory and update pointer/size
    delete[] data;
    data = newData;
    size = newSize;
}
/*================LOGIC WRITTEN USING AI RECALL IT LATER (for insert and remove functions   )================*/

};
