
#include<iostream>
#include<cstring>
using namespace std;
//========================== PART A ==============================
/*struct fullName
{
    char firstName[50];
    char middleName[50];
    char lastName[50];

};
int main()
{
    // 1. Define a FullName structure variable named info
    fullName info;
    // cin can be used instead of strcpy
    strcpy(info.lastName, "Dildar");
    strcpy(info.middleName, " "); // Or a middle name if applicable
    strcpy(info.firstName, "Muhammad");

    // 3. Display the contents of the members of the info variable
    cout << "First Name: " << info.firstName << endl;
    cout << "Middle Name: " << info.middleName << endl;
    cout << "Last Name: " << info.lastName << endl;
    return 0;
}*/
//========================== PART B ==============================
/*
struct WeatherStats {
    char city[50];
    char country[50];
    float totalRainfall;
    float highTemp;
    float lowTemp;
    float avgTemp;
};

int main() {
    WeatherStats stats;

    cout << "Enter city name: ";
    cin.getline(stats.city, 50);

    cout << "Enter country name: ";
    cin.getline(stats.country, 50);

    cout << "Enter total rainfall (mm): ";
    cin >> stats.totalRainfall;

    cout << "Enter high temperature (°C): ";
    cin >> stats.highTemp;

    cout << "Enter low temperature (°C): ";
    cin >> stats.lowTemp;

    cout << "Enter average temperature (°C): ";
    cin >> stats.avgTemp;

    // Displaying the stored information using cout...
    cout << "\n--- Weather Statistics ---" << endl;
    cout << "City: " << stats.city << endl;
    cout << "Country: " << stats.country << endl;
    cout << "Total Rainfall: " << stats.totalRainfall << " mm" << endl;
    cout << "High Temperature: " << stats.highTemp << " C" << endl;
    cout << "Low Temperature: " << stats.lowTemp << " C" << endl;
    cout << "Average Temperature: " << stats.avgTemp << " C" << endl;

    return 0;
}*/