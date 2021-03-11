//Byung Jeon Assignment 1 P1
#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

double mean(vector<double> x){
    double sum=0.00;
    for(unsigned int i=0;i<x.size();i++){
        sum += x[i];
    }
    double mean = sum/x.size();
    cout<< "Mean: "<<fixed<<setprecision(2) << mean <<endl;
    return mean;
}

double median(vector<double> y){
    sort(y.begin(), y.end());
    double median= (y[4999]+y[5000])/2;
    cout<<"Median: "<<fixed<<setprecision(2)<<median<<endl;
}

int standard_deviation(vector<double> randomArr) {
    double avg= mean(randomArr);
    median(randomArr);
    double sdHelper=0.00;
    for (unsigned int i=0;i<randomArr.size();i++){
        sdHelper += pow((randomArr[i]-avg),2 );
    }
    cout<<"Standard Deviation: "<<sqrt(sdHelper/10000)<<endl<<endl;
}


int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> n(1, 50);
    vector<double> v;
    for (int i=0; i<10000;i++) {
        v.push_back(n(gen));
    }
    cout<<"Uniform Distribution"<<endl;
    standard_deviation(v);

    vector<double> v2;
    geometric_distribution<> a;
    for(int i=0; i<10000; i++) {
        v2.push_back(a(gen));
    }
    cout<<"Bernoulli Geometric Distribution"<<endl;
    standard_deviation(v2);

    vector<double> v3;
    poisson_distribution<> b(5);
    for(int i=0; i<10000; i++) {
        v3.push_back(b(gen));
    }
    cout<<"Poisson Distribution"<<endl;
    standard_deviation(v3);

    vector<double> v4;
    normal_distribution<> c{8,2};
    for(int i=0; i<10000; i++) {
        v4.push_back(c(gen));
    }
    cout<<"Normal Distribution"<<endl;
    standard_deviation(v4);

    vector<double> v5;
    exponential_distribution<> d(3);
    for(int i=0; i<10000; i++) {
        v5.push_back(2*d(gen));
    }
    cout<<"Exponential Distribution"<<endl;
    standard_deviation(v5);
    
    return 0;
}
