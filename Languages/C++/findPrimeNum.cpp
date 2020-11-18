// Prime Number

#include <iostream>
using namespace std;

int main() {
	int n;
	int count = 0;

	cout << "Prime numbers are numbers that have only 2 factors: 1 and itself." << endl;
	cout << "Enter a positive integer: " << endl;
	cin >> n;

	while (n <= 0) {
		cout << "Invalid input. Please enter a positive integer: " << endl;
		cin >> n;
	}

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			count++;
		}
	}

	cout << n << " has " << count << " factors." << endl;

	if (count == 2) {
		cout << n << " is a prime number since it has a count of " << count << "." << endl;
		cout << n << " is only divisible by 1 and " << n << endl;
	}
	else {
		cout << n << " is NOT a prime number since it has a count of " << count << "." << endl;
	}

	return 0;
}