#include <bits/stdc++.h>

using namespace std;
const int maxN = 200005;

int N, M, rounds, arrayValues[maxN], positions[maxN];

// Function to update positions and recalculate rounds after a swap
void updateRoundsAfterSwap(int indexA, int indexB) {
    // Adjust rounds for the element at indexA
    if (positions[arrayValues[indexA] - 1] < positions[arrayValues[indexA]] && indexB <= positions[arrayValues[indexA] - 1]) rounds++;
    if (positions[arrayValues[indexA] - 1] > positions[arrayValues[indexA]] && indexB >= positions[arrayValues[indexA] - 1]) rounds--;
    if (positions[arrayValues[indexA] + 1] > positions[arrayValues[indexA]] && indexB >= positions[arrayValues[indexA] + 1]) rounds++;
    if (positions[arrayValues[indexA] + 1] < positions[arrayValues[indexA]] && indexB <= positions[arrayValues[indexA] + 1]) rounds--;

    // Update the position of the element after swapping
    // this is necessary to prevent double counting
    // when a-1, a or a, a+1 are swapped
    positions[arrayValues[indexA]] = indexB;

    // Adjust rounds for the element at indexB
    if (positions[arrayValues[indexB] - 1] < positions[arrayValues[indexB]] && indexA < positions[arrayValues[indexB] - 1]) rounds++;
    if (positions[arrayValues[indexB] - 1] > positions[arrayValues[indexB]] && indexA > positions[arrayValues[indexB] - 1]) rounds--;
    if (positions[arrayValues[indexB] + 1] > positions[arrayValues[indexB]] && indexA > positions[arrayValues[indexB] + 1]) rounds++;
    if (positions[arrayValues[indexB] + 1] < positions[arrayValues[indexB]] && indexA < positions[arrayValues[indexB] + 1]) rounds--;

    // Update the position of the element after swapping
    positions[arrayValues[indexB]] = indexA;

    // Swap the elements in the array
    swap(arrayValues[indexA], arrayValues[indexB]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Read the number of elements and the number of swap operations
    scanf("%d %d", &N, &M);

    // Read the initial array values and record their positions
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arrayValues[i]);
        positions[arrayValues[i]] = i;
    }

    // Initialize a boundary condition
    positions[N + 1] = N + 1;

    // Initialize the round count based on the initial array
    rounds = 1;
    int lastPosition = 0;
    for (int i = 1; i <= N; i++) {
        if (lastPosition > positions[i]) {
            rounds++;
        }
        lastPosition = positions[i];
    }

    // Process each swap operation and update the round count
    for (int i = 0; i < M; i++) {
        int indexA, indexB;
        scanf("%d %d", &indexA, &indexB);
        updateRoundsAfterSwap(indexA, indexB);
        printf("%d\n", rounds);
    }
}