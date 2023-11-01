#include<iostream>
using namespace std;
struct {
	int max[3];
	int allocation[3];
	int need[3];
	int state = 0; 
} P[5];
int available[3], work[3], seq[5];
int k = 0;
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> P[i].max[0] >> P[i].max[1] >> P[i].max[2] >> P[i].allocation[0] >> P[i].allocation[1] >> P[i].allocation[2] >> P[i].need[0] >> P[i].need[1] >> P[i].need[2];
	}
	cin >> available[0] >> available[1] >> available[2];
	for (int i = 0; i < 3; i++) {
		work[i] = available[i];
	}
	for (int i = 0 ; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			if (P[j].need[0] <= work[0] && P[j].need[1] <= work[1] && P[j].need[2] <= work[2] && P[j].state == 0) {
				work[0] += P[j].allocation[0];
				work[1] += P[j].allocation[1];
				work[2] += P[j].allocation[2];
				seq[k++] = j;
				P[j].state = 1;
			}
		}
	}
	if (k == 5) {
		cout << "The process is safe, safe sequence is ";
		cout << seq[0];
		for (int i = 1; i < 5; i++) {
			cout << " ¡ú " <<seq[i];
		}
	}
	else {
		cout << "The process is not safe.";
	}
	return 0;
} 
