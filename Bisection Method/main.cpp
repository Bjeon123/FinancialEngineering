//Byung Jeon Problem 2 pt1
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double calculateSolution(vector <double> fn, double xVal){
    double val=0;
    size_t i=0;
    while(i < fn.size()){
        double exp=fn[i+1];
        double co=fn[i];
        double sol = co * (pow(xVal,exp));
        val =val+sol;
        i+=2;
    }
    return val;
}

bool getSign(double num){
    if (num>0){
        return true;
    }
    else{
        return false;
    }
}


int bisectionMethod(vector<double> function,double a, double b){
    int iteration=1;
    bool solutionReached=false;
    double valOfA=calculateSolution(function,a);
    double valOfB=calculateSolution(function,b);
    bool signofA;
    bool signofB;
    if ((valOfA > 0 && valOfB > 0) || (valOfA < 0 && valOfB < 0)){
        cout<<"The values of the functions must be of opposite signs when 'a' and 'b' are plugged in"<<endl;
        return 0;
    }
    else {
        if (valOfA > 0) {
            signofA = true;
            signofB = false;
        }
        else{
            signofB= true;
            signofA= false;
        }
        while (iteration <= 1000 && solutionReached == false) {
            iteration++;
            double c = (a + b) / 2;
            if ((calculateSolution(function, c) == 0) || ((b - a) / 2)<=.001) {
                cout << "The value of the function is zero when, x is equal to " << c << endl;
                solutionReached = true;
                break;
            }
            else {
                bool signofC = getSign(calculateSolution(function, c));
                if (signofC == signofA) {
                    a = c;
                }
                else if (signofB == signofC){
                    b = c;
                }
            }
            if (iteration==1000){
                cout<<"No solution"<<endl;
            }
        }
    }
    return 0;
}

int main() {
    vector<double> coefficients;
    int terms;
    cout<<"How many terms will your polynomial have?"<<endl;
    cin>>terms;
    if (terms<=0 || terms>4){
        cerr<<"Please enter a number from 1 to 4" << endl;
        return 1;
    }
    for(int i=0;i<terms;i++){
        double coef=0;
        double exp=0;
        cout<<"What will be the coefficient of this term?"<<endl;
        cin>>coef;
        cout<<"What will be the exponential value of this term?"<<endl;
        cin>>exp;
        coefficients.push_back(coef);
        coefficients.push_back(exp);
    }
    double firstVar;
    double secondVar;
    cout<<"Enter the first x value for the bisection method"<<endl;
    cin>>firstVar;
    cout<<"Enter the second x value for the bisection method"<<endl;
    cin>>secondVar;
    bisectionMethod(coefficients,firstVar,secondVar);
    return 0;
}
