#include <iostream>
#include <vector>
using namespace std;

void floodFill(vector<vector<int>>& image, int x, int y, int originalColor, int newColor) {
    int height = image.size();
    int width = image[0].size();

    if (x < 0 || x >= height || y < 0 || y >= width || image[x][y] != originalColor || image[x][y] == newColor) {
        return;
    }

    image[x][y] = newColor;

    floodFill(image, x + 1, y, originalColor, newColor);
    floodFill(image, x - 1, y, originalColor, newColor);
    floodFill(image, x, y + 1, originalColor, newColor);
    floodFill(image, x, y - 1, originalColor, newColor);
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1}
    };

    int start_x = 2;
    int start_y = 2;
    int newColor = 2;
    int originalColor = image[start_x][start_y];

    floodFill(image, start_x, start_y, originalColor, newColor);

    // Print the filled image
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
