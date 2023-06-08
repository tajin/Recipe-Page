#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Student
{
    int id;
    double gpa; 
    string major;

    string stringify()
    {
        stringstream sout;
        sout << "[" << id << ", " << gpa << ", " << major << "]\n";
        return sout.str();
    }
};

void selctByMajor (vector<Student>& vDB, vector<Student>& vSolution, string majorValue);
//vector<Student> selectMinus (vector<Student>& v1, vector<Student>& v2);

main()
{
    cout << "Run";
    vector<Student> vDB;
    Student s1{400, 3.4, "MAGIC"};
    Student s2{400, 3.4, "MATH"};
    Student s3{300, 4.4, "MATH"};
    Student s4{700, 5.4, "MAGIC"};
    vDB.push_back(s1);
    vDB.push_back(s2);
    vDB.push_back(s3);
    vDB.push_back(s4);

    vector<Student> vSolution;
    selctByMajor(vDB, vSolution, "MATH");

    cout << "(1)";
    for(int i = 0; i < vDB.size(); i++)
    {
        cout << vDB[i].stringify();
    }

}

void selctByMajor (vector<Student>& vDB, vector<Student>& vSolution, string majorValue)
{
    for (int i = 0; i < vDB.size(); i ++)
    {
        if(vDB[i].major == majorValue)
        {
            vSolution.push_back(vDB[i]);
        }
    }
}


