#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// linear regression
// gradient descent method

const int testNum = 1;
const int numData = 10000;
const double lr = 0.000000001; // Q1 learning rate
const double lr2 = 0.0000000000000001; // Q2 learning rate

//Class for Q1 
class LinearHypothesis {
public:
	double a = 0.0;
	double b = 0.0;
public:
	double getY(const double& x_input) {
		return (a * x_input + b + rand()/RAND_MAX);
	}
};

//Class for Q1
class LinearHypothesis2 {
public:
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
public:
	double getY(const double& x_input) {
		return (a * x_input*x_input + b *x_input + c);
	}
};

int main() {

	// initialization
	srand((unsigned int)time(NULL)); // random seed

	double study_time[numData];
	double score[numData];

	for (int i = 0; i < numData; i++) {
		study_time[i] = i; 
		score[i] = 3 * i + 1;
	}

	// Q1
	LinearHypothesis study;

	for (int r = 0; r < testNum; r++) {
		for (int i = 0; i < numData; i++) {
			const double error = (score[i] - study.getY(study_time[i]));
			const double sqr_error = error * error;

			const double x = study_time[i];
			const double d_error_over_d_a = 2.0 * -error * x;
			const double d_error_over_d_b = 2.0 * -error * 1.0;

			study.a -= d_error_over_d_a * lr;
			study.b -= d_error_over_d_b * lr;

			cout << "a: " << study.a << ", " << "b: " << study.b << ", " << "Y: " << study.getY(study_time[i]) << endl;
		}
		cout << endl;
	}

	//Q2
	LinearHypothesis2 study2;

	for (int r = 0; r < testNum; r++) {
		for (int i = 0; i < numData; i++) {
			const double error = (score[i] - study2.getY(study_time[i]));
			const double sqr_error = error * error; 

			const double x = study_time[i];
			const double d_error_over_d_a = 2.0 * -error * x * x;
			const double d_error_over_d_b = 2.0 * -error * x;
			const double d_error_over_d_c = 2.0 * -error * 1.0;

			study2.a -= d_error_over_d_a * lr2;
			study2.b -= d_error_over_d_b * lr2;
			study2.c -= d_error_over_d_c * lr2;

			cout << "a: " << study2.a << ", " << "b: " << study2.b << ", " << "c: " << study2.c << ", " << "Y: " << study2.getY(study_time[i]) << endl;
		}
		cout << endl;
	}

	return 0;
}