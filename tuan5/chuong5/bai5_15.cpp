#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int nge = -1;
            int nge_index = -1;

            // Tìm Next Greater Element (NGE)
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) {
                    nge = a[j];
                    nge_index = j;
                    break;
                }
            }

            if (nge != -1) {
                int nse_of_nge = -1;
                // Tìm Next Smaller Element (NSE) của NGE
                for (int k = nge_index + 1; k < n; k++) {
                    if (a[k] < nge) {
                        nse_of_nge = a[k];
                        break;
                    }
                }
                ans[i] = nse_of_nge;
            } else {
                ans[i] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}