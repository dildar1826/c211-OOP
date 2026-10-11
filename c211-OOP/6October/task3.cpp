#include<iostream>
using namespace std;
class Student{
    char rollNo[11]; // sample roll no= BSEF25A518
    int semester;
    float cgpa;
    char name[50];
public:
    void myStrcpy(char dest[], const char* src) {
    int i = 0;
    // Copy characters one by one until the null terminator is reached
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    // append null terminator at the end of the destination string
    dest[i] = '\0';
    }
    void setRollNo(const char * r){
        /* =========================================================
                          REMAINING CODE 
                (CHECK IF INTEGRAL PART IS BETWEEN 1 AND 999)
        ============================================================*/
        myStrcpy(rollNo, r);
    }
    void setSemester(int s){
        // we can do condition check here..... so that s in between (1,8)
        semester = s;
    }
    void setName(const char * n){
        myStrcpy(name, n);
    }
    void setGPA(float g){
        cgpa = g; // we can do condition check here..... so that g in between (0,4)
    }
    const char * getRollNo(){
        /*=====QUESTION=====
         we cant return char* becuase this means the original variable can be changed so
         thats why we used const char* so that the original variable will not be changed....*/
        return rollNo;
    }
    int getSemester(){
        return semester;
    }
    const char * getName(){
        return name;
    }
    float getGPA(){
        return cgpa;
    }
    bool isStudentDropout(){
        if(semester == 1 && cgpa < 1.5)
            return true;
        else if(semester == 2 && cgpa < 1.7)
            return true;
        else
            return false;
    
    }
    
    bool isStudentOnProbation(){
        if(semester == 1 && cgpa >=1.5 && cgpa < 2.0)
            return true;
        else if(semester == 2 && cgpa >= 1.7 && cgpa < 2.0)
            return true;
        else
            return false;
    }


};

int main()
{
 Student s1;
    s1.setRollNo("BSEF25A518");
    s1.setSemester(1);
    s1.setName("MUHAMMAD DILDAR");
    s1.setGPA(1.4);
    cout<<"Roll No: "<<s1.getRollNo()<<endl;
    cout<<"Semester: "<<s1.getSemester()<<endl;
    cout<<"Name: "<<s1.getName()<<endl;
    cout<<"GPA: "<<s1.getGPA()<<endl;
    if(s1.isStudentDropout())
        cout<<"Student is a dropout"<<endl;
    else if(s1.isStudentOnProbation())
        cout<<"Student is on probation"<<endl;
    else
        cout<<"Student is in good standing"<<endl;
}