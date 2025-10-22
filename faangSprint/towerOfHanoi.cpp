#include <bits/stdc++.h>
using namespace std;

struct Frame {
    int n;
    char from, to, aux;
    int phase; 
};

void towerOfHanoiIterative(int n, char from, char to, char aux) {
    stack<Frame> st;

    st.push({n, from, to, aux, 0});

    while (!st.empty()) {
        Frame &top = st.top();

        if (top.n == 1) {
            cout << "Move disk 1 from " << top.from << " to " << top.to << "\n";
            st.pop(); 
            continue;
        }

        if (top.phase == 0) {
            top.phase = 1; 
            st.push({top.n - 1, top.from, top.aux, top.to, 0});
        } else {
            cout << "Move disk " << top.n << " from " << top.from << " to " << top.to << "\n";
            st.pop();
            st.push({top.n - 1, top.aux, top.to, top.from, 0});
        }
    }
}

int main() {
    int n = 3; 
    towerOfHanoiIterative(6, 'A', 'C', 'B');
    return 0;
}
