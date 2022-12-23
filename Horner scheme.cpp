#include <iostream> 
#include <iomanip>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<double> divisors(double del) {
	vector<double> masDel;
	masDel.clear();
	for (int i = 1; i <= pow(abs(del), 0.5) + 1; i++)
		if (del / i == (int)(del / i)) {
			masDel.push_back(i);
			masDel.push_back(-i);
			masDel.push_back(del / i);
			masDel.push_back(-(del / i));
		}
	return masDel;
}

int main()
{
	int count; 	double input;
	vector<double> fx, divN, divM;
	set<double> alpha;

	cout << "Search for solutions to the equation by Horner's scheme\n\n";

	cout << "----------------------------\n"
		<< "EXAMPLE\n\nMax degree : 5\n"
		<< "F(x) : 10 17 13 2 -5 -1 \n(without X and degree)"
		<< "\n----------------------------\n\n\n ";

	cout << "Max degree of X in f(x): ";
	cin >> count;
	count++;

	cout << "F(x): ";
	for (int i = 0; i < count; i++) {
		cin >> input;
		fx.push_back(input);
	}

	divN = divisors(fx[0]);
	divM = divisors(fx[fx.size() - 1]);

	for (int i = 0; i < divM.size(); i++)
		for (int j = 0; j < divN.size(); j++)
			alpha.insert(divM[i] / divN[j]);

	vector<double> alphaVec(alpha.begin(), alpha.end()), fxTmp, ans;

	for (int i = 0; i <= fx.size(); i++)
		cout << "--------+";

	for (int a = 0; a < alpha.size(); a++) {
		fxTmp.clear();
		cout << "\n" << setw(8) << alphaVec[a] << "|";
		for (int i = 0; i < fx.size(); i++) {
			if (i == 0) {
				cout << setw(8) << fixed << setprecision(2) << static_cast<double>(fx[0]) << "|";
				fxTmp.push_back(fx[0]);
				continue;
			}

			fxTmp.push_back(alphaVec[a] * fxTmp[i - 1] + fx[i]);
			cout << setw(8) << fixed << setprecision(2) << static_cast<double>(fxTmp[i]) << "|";
			
		}
		if (fxTmp[fxTmp.size() - 1] == 0) ans.push_back(alphaVec[a]);
	}
	cout << "\n";
	for (int i = 0; i <= fx.size(); i++)
		cout << "--------+";

	cout << "\n\nSolutions: ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "; ";
	}
	cout << "\n\n";
}