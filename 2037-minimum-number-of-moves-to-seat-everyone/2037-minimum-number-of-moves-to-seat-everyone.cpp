class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // sort then iterate on them ;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int i = 0, moves = 0;
        while (i < seats.size()) {
            moves += abs(seats[i] - students[i]);
            ++i;
        }
        return moves;
    } 
};