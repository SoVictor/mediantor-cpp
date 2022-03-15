#include <iostream>
#include <memory>

#include "mediantor.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	int mediantor_type = -1;
	while (mediantor_type < 0 || mediantor_type >= static_cast<int>(Mediantors::kMediantorsNumber)) {
		cout << "Please choose which Mediantor implementation to use by writing a single number: " << endl;
		cout << "0 - Mediantor as two heaps" << endl;
		cout << "1 - Mediantor as SQRT-decomposition" << endl;
		cout << "2 - Mediantor as a sorted list" << endl;
		cin >> mediantor_type;
	}

	cout << endl << "Please provide an input in a format described in README:" << endl;

	int n;
	cin >> n;

	std::unique_ptr<IMediantor> mediantor = MakeMediantor(static_cast<Mediantors>(mediantor_type), n);

	for (int i = 0; i < n; i++) {
		int operation;
		cin >> operation;
		if (operation) {
			int x;
			cin >> x;
			mediantor->insert(x);
		}
		else {
			cout << mediantor->take() << endl;
		}
	}

	return 0;
}
