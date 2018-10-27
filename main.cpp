#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;


void print_vector(const vector<int> &i);
void bubble_sort(vector<int> y);
void selection_sort(vector<int> y);
void quick_sort( vector<int> & items );
void insertion_sort(vector<int> &y);
int r1,r2,r3,r4,w1,w2,w3,w4;
int main() {
    vector<int> my_int;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
void print_vector(const vector<int> &y) {
    for (int i = 0; i < 10; ++i) {
        cout << y[i] << ", ";
    }
    cout << endl;
}

void bubble_sort(vector<int> y) {
    int num_swaps = 1;
    // j is the index where the sorted elements start
    for (int j = y.size(); j > 0 && num_swaps > 0; --j) {
        num_swaps = 0;
        // i is the current index when we iterate through the vector
        for (int i = 0; i < j - 1; ++i) {
            if (y[i]> y[i + 1]) {
                // swap
                int temp = y[i + 1];
                y[i + 1] = y[i];
                y[i] = temp;
                ++num_swaps;
                r1=r1+2;
                w1=w1+2;
            }
            r1=r1+2;
        }
    }
    print_vector(y);
}
void selection_sort(vector<int> y) {
    // i represents the starting index of unsorted elements
    for (int i = 0; i < y.size(); ++i) {
        int current_min_index = i;
        // j represents the current index in the vector iteration
        for (int j = i+1; j < y.size(); ++j) {
            r2=r2+1;
            if (y[j]< y[current_min_index]) {
                current_min_index = j;
            }
        }
        if (i != current_min_index) {
            // swap v[i] and v[current_min_index]
            int temp = y[i];
            y[i] = y[current_min_index];
            y[current_min_index]= temp;
            w2=w2+1;
        }
    }
    print_vector(y);
}



void quick_sort( vector<int> & items )
{
    // if there are 0 or 1 items, no need to sort.
    if( items.size( ) > 1 )
    {
        vector<int> smaller;
        vector<int> same;
        vector<int> larger;

        auto chosenItem = items[ items.size( ) / 2 ];
        r3++;
        for( auto & i : items )
        {
            if( i < chosenItem ) {
                smaller.push_back(std::move(i));
                w3++;
            }
            else if( chosenItem < i ) {
                larger.push_back(std::move(i));
                w3++;
            }
            else {
                same.push_back(std::move(i));
                w3++;
            }
        }

        quick_sort( smaller );     // Recursive call!
        quick_sort( larger );      // Recursive call!

        // Now that both sides are sorted, put all the pieces back into the original items vector

        // move the smaller vector to the beginning of the items vector
        std::move( begin( smaller ), end( smaller ), begin( items ) );
        // move the same vector to starts after the smaller elements in the items vector
        std::move( begin( same ), end( same ), begin( items ) + smaller.size( ) );
        // move the larger vector to the end of the items vector
        std::move( begin( larger ), end( larger ), end( items ) - larger.size( ) );

    }
}

void insertion_sort(vector<int> &y) {
    // i represents the starting index of unsorted elements
    for (int i = 1; i < y.size(); ++i) {
        // j represents the index of the sorted elements
        // from lowest to highest, looking for where to insert v[i]
        for (int j = 0; j < i; ++j) {
            r4=r4+2;
            if (y[i] <= y[j]) {
                int inserted_value = y[i];
                // need to insert v[i] at index j
                // we need to move all the elements from index j to i to the right
                for (int k = i; k > j; --k) {
                    y[k] = y[k-1];
                    r4++;
                    w4=w4+2;
                }
                y[j] = inserted_value;
                break;
            }
        }
    }
}
