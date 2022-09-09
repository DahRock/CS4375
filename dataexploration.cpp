#include <bits/stdc++.h>
using namespace std;

string line;
string rm_in, medv_in;
ifstream inFS;
vector<double> rm;
vector<double> medv;

vector<double> testVector;
vector<double> testVector2;

double findSum(vector<double>);
double findMean(vector<double>);
double findMedian(vector<double>);
double findRange(vector<double>);
double findStdDev(vector<double>);
double findCov(vector<double>, vector<double>);
double findCorr(vector<double>, vector<double>);

int main(int argc, char** argv) {
    cout << "Attempting to open the file Boston.csv" << endl;

    inFS.open("Boston.csv");

    if(!inFS.is_open()) {
        cout << "There was an issue opening the file Boston.csv" << endl;
        return 1; // return 1 cause 1 indicates an error
    }

    getline(inFS, line); // read the first line as I have no use for it


    /*
        Read in all of the contents of the data file each in it's own string one
        line at a time and then convert the strings to float point variables and 
        add them to their respective vectors.
    */
    while(inFS.good()) {
        getline(inFS, rm_in, ',');
        getline(inFS, medv_in, '\n');

        rm.push_back(stof(rm_in));
        medv.push_back(stof(medv_in));
    }
    inFS.close();
    cout << "Sum of rm = "                  <<  findSum(rm)        << endl;
    cout << "Mean of rm = "                 <<  findMean(rm)       << endl;
    cout << "Median of rm = "               <<  findMedian(rm)     << endl;
    cout << "Range of rm = "                <<  findRange(rm)      << endl;
    cout << "StdDev of rm = "               <<  findStdDev(rm)     << endl;
    cout << "Sum of medv = "                <<  findSum(medv)      << endl;
    cout << "Mean of medv = "               <<  findMean(medv)     << endl;
    cout << "Median of medv = "             <<  findMedian(medv)   << endl;
    cout << "Range of medv = "              <<  findRange(medv)    << endl;
    cout << "StdDev of medv = "             <<  findStdDev(medv)   << endl;
    cout << "Cov between rm and medv = "    <<  findCov(rm, medv)  << endl;
    cout << "Corr between rm and medv = "   <<  findCorr(rm, medv) << endl;
    return 0;
}
double findSum(vector<double> vec) {
    double sum = 0;

    for(int i = 0; i < vec.size(); i++) {
        sum = sum + vec[i];
    }
    return sum;
}
double findMean(vector<double> vec) {
    double sum = findSum(vec);
    return sum / vec.size();
}
double findMedian(vector<double> vec) {
    sort(vec.begin(), vec.end());

    int size = vec.size();
    
    if(size % 2 == 0)
        return (vec[size / 2] + vec[size / 2 + 1]) / 2;
    return vec[(size + 1) / 2];
}
double findRange(vector<double> vec) {
    sort(vec.begin(), vec.end());

    return vec[vec.size() - 1] - vec[0];
}
double findStdDev(vector<double> vec) {
    double sum = 0;
    double avg = findMean(vec);

    for(int i = 0; i < vec.size(); i++) {
        sum = sum + (vec[i] - avg) * (vec[i] - avg);
    }
    return sqrt(sum / (vec.size() - 1));
}
double findCov(vector<double> v1, vector<double> v2) {
    double v1_avg = findMean(v1);
    double v2_avg = findMean(v2);
    double cov;
    double n;
    
    n = v1.size();
    for(int i = 0; i < v1.size(); i++) {
        cov = cov + (v1[i] - v1_avg) * (v2[i] - v2_avg);
    }

    return cov / (n - 1);
}
double findCorr(vector<double> v1, vector<double> v2) {
    double cov = findCov(v1, v2);
    double stddev1 = findStdDev(v1);
    double stddev2 = findStdDev(v2);

    return cov / (stddev1 * stddev2);
}