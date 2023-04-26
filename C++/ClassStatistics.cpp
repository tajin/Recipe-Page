// S122-Perez-Class-Statistics.cpp 
// Author: Angel Perez
// Goal: REad a smaple representnig student grades. Calculate max, min, count, avg, std.
//       Each grade must be between 0-100
// ---------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

//prtotype
void experiment1();
int Max(int[], int);
int Min(int[], int);
int getGrade(int, int);
double calculateAverage(int [], int);
double calculateStandardDeviation(int[], int, double);

int main()
{
    experiment1();
}

//----------------------------------------------------------------------------------------
//User Defined Methods
//----------------------------------------------------------------------------------------

void experiment1()
{
    int grade;
    int low = 0, high = 100;

    const int N = 40;  //At most 40 students
    int scores[N], counter = 0;
    char response;

    do {

    grade = getGrade(low, high);
    scores[counter] = grade;

    counter++;

    cout << "More data (y/n): ";
    cin >> response;
    cout << endl;

    } while (response == 'y' && counter < N-1);

   //Debugging
    /*for (int j = 0; j < counter; j++) {
        cout << "score[" << j << "] = " << scores[j] << endl;
    }
    */

    double avg = calculateAverage(scores, counter);
    cout << "The average of the sample is " << avg << endl;

    double standardDeviation = calculateStandardDeviation(scores, counter, avg);
    cout << "THe standard deviation is:  " << standardDeviation << endl;

    int max = Max(scores, counter);
    cout << "The highest score is: " << max << endl;

    int min = Min(scores, counter);
    cout << "The lowest score is:  " << min << endl;

}

int getGrade(int low, int high)
{
    int grade;
    do
    {
        cout << "Please input value in range [" << low << ", " << high << "]: ";
        cin >> grade;

        if (grade < low || grade > high) {
            cout << "Error - Please input value in range.\n\n";
        }
        else {
            return grade;
        }

    } while (true);
}

double calculateAverage(int scores[], int counter)
{
    double result = 0;

    for (int i = 0; i < counter; i++) {
        result = result + scores[i];
    }

    return (result / counter);

}

double calculateStandardDeviation(int scores[],int counter,double avg) {

    double result = 0;

    for (int i = 0; i < counter; i++) {
        result += pow(scores[i] - avg, 2);
    }

    return sqrt(result / counter);

}

int Max(int scores[], int counter) {
    int max = 0;

    for (int i = 0; i < counter; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }

    return max;

}

int Min(int scores[], int counter) {
    int min = 100;

    for (int i = 0; i < counter; i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
    }

    return min;

}