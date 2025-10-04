#include <iostream>
#include <cstring>
using namespace std;

void search(char pat[], char txt[]) {
    int m = strlen(pat);
    int n = strlen(txt);

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "ABA";
    search(pat, txt);
    return 0;
}
