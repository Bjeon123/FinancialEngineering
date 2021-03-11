
#include <iostream>
#include <math.h>
#include <random>
#include <iomanip>

using namespace std;

random_device rd;
mt19937 gen(rd());

bool pointInEllipse(double x, double y){
    double value =  5*pow(x,2)+(21*x*y)+25*pow(y,2);
    if(value<=9){
        cout<<"yes"<<endl;
        return true;
    }
    else{
        cout<<"no"<<endl;
        return false;
    }
}

double montecarlo (){
    int successes=0;
    uniform_real_distribution<> x(-7, 7);
    for (int i = 0; i < 10000000; i++) {
        double randomX = x(gen);
        double randomY = x(gen);
        if(pointInEllipse(randomX,randomY)){
            successes++;
        }
    }
    cout<<successes<< " Successes "endl;
    cout<<"Estimated Area: "<<fixed<<setprecision(4)<<(successes/10000000)*196<<endl;
}


int main() {
    montecarlo();
    return 0;
}
