// #include <string>
// #include <set>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     int maximumGain(string a1, int x, int y) {
//         string s = a1;
//         if (y > x) {
//             // Process "ba" pairs first
//             int score = 0;
//             int ctrb = 0;
//             int n = s.length();
//             set<pair<int, int>> st;
//             int last = -1;

//             // Detect "ba" pairs
//             for (int i = 0; i < n; i++) {
//                 char temp = s[i];
//                 if (temp == 'b') {
//                     ctrb++;
//                     last = i;
//                 } else if (temp == 'a' && ctrb > 0) {
//                     ctrb--;
//                     st.insert({last, i});
//                     last--;
//                 } else if(temp!='a') {
//                     ctrb = 0;
//                     last = -1;
//                 }
//             }

//             set<int> todel;
            
//             score += st.size() * y;
//             for (auto i : st) {
//                 todel.insert(i.first);
//                 todel.insert(i.second);
//             }

//             vector<int> v(todel.begin(), todel.end());
//             reverse(v.begin(), v.end());

//             for (int i = 0; i < v.size(); i++) {
//                 s.erase(v[i], 1);
//             }

//             // Process "ab" pairs
//             int ctra = 0;
//             int n2 = s.length();
//             set<pair<int, int>> st2;
//             last = -1;

//             for (int i = 0; i < n2; i++) {
//                 char temp = s[i];
//                 if (temp == 'a') {
//                     ctra++;
//                     last = i;
//                 } else if (temp == 'b' && ctra > 0) {
//                     ctra--;
//                     st2.insert({last, i});
//                     last--;
//                 } else if(temp!='b') {
//                     ctra = 0;
//                     last = -1;
//                 }
//             }

//             set<int> todel2;
//             score += st2.size() * x;
//             for (auto i : st2) {
//                 todel2.insert(i.first);
//                 todel2.insert(i.second);
//             }

//             vector<int> v2(todel2.begin(), todel2.end());
//             reverse(v2.begin(), v2.end());

//             for (int i = 0; i < v2.size(); i++) {
//                 s.erase(v2[i], 1);
//             }

//             return score;

//         } else {
//             // Process "ab" pairs first
//             int score = 0;
//             int ctra = 0;
//             int n2 = s.length();
//             set<pair<int, int>> st2;
//             int last = -1;

//             for (int i = 0; i < n2; i++) {
//                 char temp = s[i];
//                 if (temp == 'a') {
//                     ctra++;
//                     last = i;
//                 } else if (temp == 'b' && ctra > 0) {
//                     ctra--;
//                     st2.insert({last, i});
//                     last--;
//                 } else {
//                     ctra = 0;
//                     last = -1;
//                 }
//             }

//             set<int> todel2;
//             score += st2.size() * x;
//             for (auto i : st2) {
//                 todel2.insert(i.first);
//                 todel2.insert(i.second);
//             }

//             vector<int> v2(todel2.begin(), todel2.end());
//             reverse(v2.begin(), v2.end());

//             for (int i = 0; i < v2.size(); i++) {
//                 s.erase(v2[i], 1);
//             }

//             // Process "ba" pairs
//             int ctrb = 0;
//             int n = s.length();
//             set<pair<int, int>> st;
//             last = -1;

//             for (int i = 0; i < n; i++) {
//                 char temp = s[i];
//                 if (temp == 'b') {
//                     ctrb++;
//                     last = i;
//                 } else if (temp == 'a' && ctrb > 0) {
//                     ctrb--;
//                     st.insert({last, i});
//                     last--;
//                 } else {
//                     ctrb = 0;
//                     last = -1;
//                 }
//             }

//             set<int> todel;
//             score += st.size() * y;
//             for (auto i : st) {
//                 todel.insert(i.first);
//                 todel.insert(i.second);
//             }

//             vector<int> v(todel.begin(), todel.end());
//             reverse(v.begin(), v.end());

//             for (int i = 0; i < v.size(); i++) {
//                 s.erase(v[i], 1);
//             }

//             return score;
//         }

//         return -1; // This return will never be reached, so it can be removed
//     }
// };




class Solution {
public:
    int maximumGain(string a1, int x, int y) {
        string s = a1;
        int score = 0;

        // Function to process and remove pairs
        auto processPairs = [&](char first, char second, int scoreGain) {
            // set<pair<int, int>> st;
            int n = s.length();
            vector<int> toDel;
            int countFirst = 0;
            int lastFirst = -1;
            stack<int> st;
            for (int i = 0; i < n; i++) {
                if (s[i] == first) {
                    st.push(i);
                    // lastFirst = i;
                } else if (s[i] == second && st.size()>0 && s[st.top()]==first) {
                    // countFirst--;
                    // st.insert({lastFirst, i});
                    // toDel.push_back(lastFirst);
                    // toDel.push_back(i);
                    // lastFirst--;
                    toDel.push_back(i);
                    toDel.push_back(st.top());
                    st.pop();
                    
                } else {
                    // countFirst = 0;
                    // lastFirst = -1;
                    while(!st.empty()){
                        st.pop();
                    }
                }
            }

            score += toDel.size()/2 * scoreGain;
            sort(toDel.begin(), toDel.end(), greater<int>());

            for (int idx : toDel) {
                s.erase(s.begin() + idx);
            }
        };

        if (y > x) {
            processPairs('b', 'a', y);  // process "ba" pairs
            processPairs('a', 'b', x);  // process "ab" pairs
        } else {
            processPairs('a', 'b', x);  // process "ab" pairs
            processPairs('b', 'a', y);  // process "ba" pairs
        }

        return score;
    }
};