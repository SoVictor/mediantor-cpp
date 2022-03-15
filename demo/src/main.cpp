#include "i_mediantor.h"
#include "mediantor_sqrt_decomp.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	int n;
	cin >> n;

	std::unique_ptr<IMediantor> mediantor = std::make_unique<MediatorSqrtDecomp>(n);

	for (int i = 0; i < n; i++)
	{
		int operation;
		cin >> operation;
		if (operation) {
			int x;
			std::cin >> x;
			mediantor->insert(x);
		}
		else {
			cout << mediantor->take() << endl;
		}
	}

	return 0;
}
