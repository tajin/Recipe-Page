#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    
    string user_color_1, user_color_2, final_color;
    int color_value;
    std::map<std::string, int> colors{{"red", 1}, {"blue", 2}, {"yellow", 3}};
    
    cout << "Please select a primary color (Red, Blue, Yellow):       ";
    getline (cin, user_color_1);
    cout << "Please select another primary color (Red, Blue, Yellow): ";
    getline (cin, user_color_2);

    transform(user_color_1.begin(), user_color_1.end(), user_color_1.begin(), ::tolower);
    transform(user_color_2.begin(), user_color_2.end(), user_color_2.begin(), ::tolower);

    color_value = colors[user_color_1] + colors[user_color_2];

    if (color_value == 3){
        final_color = "Purple";
    };
    if (color_value == 4){
        final_color = "Orange";
    };
    if (color_value == 5){
        final_color = "Green";
    }

    cout << user_color_1 << " mixed with " << user_color_2 << " makes " << final_color << endl;

    return 0;
}
