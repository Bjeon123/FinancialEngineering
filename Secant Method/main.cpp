//Byung Jeon Problem 2 pt2
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

int iteration=0;
void secantMethod(vector<double> function, double a, double b){
    double solutionB=calculateSolution(function,b);
    double solutionA=calculateSolution(function,a);
    double c = b-((solutionB * (b - a)) / (solutionB - solutionA));
    double solutionC=calculateSolution(function,c);
    while(fabs(solutionC) <=.001){
        solutionB=calculateSolution(function,b);
        solutionA=calculateSolution(function,a);
        c= b-((solutionB * (b - a)) / (solutionB - solutionA));
        a=b;
        b=c;
        iteration++;
        if (iteration>=1000){
            cout<<"No Solution was found after maximum iterations"<<endl;
            break;
        }
    }
    cout<<"The root found is "<<c<<endl;
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
    cout<<"Enter the first guess value for the secant method"<<endl;
    cin>>firstVar;
    cout<<"Enter the second guess value for the secant method"<<endl;
    cin>>secondVar;
    secantMethod(coefficients,firstVar,secondVar);
    return 0;
}
