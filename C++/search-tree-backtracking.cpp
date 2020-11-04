#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> best_path; // collection of tracks
int best_answer; // best sum

void DFS_Backtracking (vector<int>tracks_duration, vector<int>path, int sum, int it, int num_tracks, int n_minutes) {

	// adds the current track in path
	path.push_back(tracks_duration[it]);
	sum += tracks_duration[it]; // adds to the sum

	// if sum is better than the current best answer, we change
	if (sum > best_answer) {
		best_answer = sum;
		best_path = path;
	}

	// checks if the final sum is less or equal than the number of minues availabe
	for (int i = it+1; i < num_tracks; i++) {
		if (sum + tracks_duration[i] <= n_minutes)
			DFS_Backtracking (tracks_duration, path, sum, i, num_tracks, n_minutes); // checks next track
	}
	
	return;
}

int main (void) {

	int n_minutes = 0;
	int num_tracks = 0;
	int duration = 0; 

	while (cin >> n_minutes) { 
		cin >> num_tracks;
		vector<int>tracks_duration;

		for (int i = 0; i < num_tracks; i++) {
			cin >> duration;
			tracks_duration.push_back(duration);
		}		
		best_answer = 0; 
		for (int i = 0; i < num_tracks; i++) {
			vector<int>path; // keeps the path we are starting with
			DFS_Backtracking (tracks_duration, path, 0, i, num_tracks, n_minutes);
		}

		// prints answer
		for(int k = 0; k < (int)best_path.size(); k++){
            printf("%d ", best_path[k]);
		}
        printf("sum:%d\n", best_answer);	
	}
	return 0;
}
