//First passing attempt
class Solution {
public:
    bool isPalindrome(int x) {
        int holder = x,  lenofx = 0, a, b; 
        long int power;
        vector<int> listx;
        vector<int> listreversex;
        //Find value of 
        if (x < 0){
            return false;
        }

        while (holder!=0){
            lenofx ++;
            holder /= 10;
        }
        //Prints backwards
        for (int i= 0; i < lenofx; i++){

         power = pow(10, i);

         if (i == 0){
            a = (x%10);
         }

         else if(i == lenofx){
            a = (x/pow(10,i));
         }

         else{
          power = pow(10,i);
          a = ((x / power)% 10); 
         }
        
         cout << a << "/";
         
         listreversex.push_back(a);

        }

        cout << endl << endl;
        
        //prints forwards
        for (int j = lenofx; j > 0; j--){
         
         power = pow(10, j);
         //Gets last int of x
         if (j == 1){
            b = (x%10);
         }
         //Gets first int of x
         else if(j == lenofx){
            b = (x/pow(10,lenofx-1));
         }
         //supposed to get numbers in between
         else{
          b = (x % power)/pow(10,j-1); 
         }

         //Debugging
         cout<< "lenofx: " << j <<  " = ";
         cout <<b<< endl;
         
         listx.push_back(b);

        }

        if (listreversex == listx){
            return true;
        }
        else{
            return false;
        }
        
    }
};