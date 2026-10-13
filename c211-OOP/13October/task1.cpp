#include<iostream>
using namespace std;

class Array
{
    int * data; // pointer to the array of type int
    int capacity;

    int isValidIndex(int index){
        return (index >= 0 && index < capacity);
    }
    public:
        Array(int cap = 0)
        {
            if (cap < 0)
            {
                cap = 0;
            }
            capacity = cap;
            data = new int[capacity];
        }

        ~Array()
        {
            delete [] data;
            data = nullptr;
            capacity = 0;
        }
        Array(const Array & other)
        {
            capacity = other.capacity;
            data = new int[capacity];
            for (int i = 0; i < capacity; i++)
            {
                data[i] = other.data[i];
            }
        }
        int & getSet(int index)
        {
            // insert value at given index
            if (isValidIndex(index))
            {
                return data[index];
            }
            // If index is not valid, return the first element
            return data[0];
        }
        int getCapacity()
        {
            //return the size of array
            return capacity;
        }
        void reSize(int newCapacity)
        {
            if (newCapacity < 0)
            {
                newCapacity = 0;
            }
            // preserving the old data..
            int * oldData = data;
            int oldCapacity = capacity;
            // creating new array with new capacity
            data = new int[newCapacity];
            capacity = newCapacity;
            // copying the old data to new array
            for (int i = 0; i < oldCapacity && i < newCapacity;i++)
                {
                    data[i] = oldData[i];
                }
        }

};

int main(){
    Array arr(5);
    Array arr2 = arr; // copy constructor is called
    cout << "Capacity of arr2: " << arr2.getCapacity() << endl;
    arr2.reSize(10);
    cout << "Capacity of arr2 after resizing: " << arr2.getCapacity() << endl;
}