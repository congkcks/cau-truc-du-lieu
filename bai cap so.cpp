#include <vector>
#include<bits/stdc++.h>

int longestSequence(const std::vector<std::pair<int, int>>& v) {
    // S?p x?p m?ng theo ph?n t? th? hai c?a m?i c?p
    std::sort(v.begin(), v.end(),  {
        return a.second < b.second;
    });

    int longest = 0;  // Ð? dài c?a chu?i dài nh?t
    int length = 0;   // Ð? dài c?a chu?i hi?n t?i
    int end = -1;     // K?t thúc c?a chu?i hi?n t?i

    // Duy?t qua m?ng
    for (const auto& pair : v) {
        // N?u c?p s? hi?n t?i không thu?c chu?i hi?n t?i, k?t thúc chu?i hi?n t?i
        if (pair.first > end) {
            // C?p nh?t d? dài c?a chu?i dài nh?t n?u c?n
            longest = std::max(longest, length);
            // B?t d?u m?t chu?i m?i
            length = 1;
            end = pair.second;
        } else {
            // N?u c?p s? hi?n t?i thu?c chu?i hi?n t?i, tang d? dài c?a chu?i
            length++;
        }
    }

    // Ki?m tra m?t l?n n?a sau khi duy?t xong m?ng
    longest = std::max(longest, length);

    return longest;
}

int main() {
    // T?o m?t vector ch?a các c?p s?
    std::vector<std::pair<int, int>> v = {{1, 5}, {2, 3}, {4, 1}, {6, 4}};

    // Tính d? dài c?a chu?i dài nh?t th?a mãn di?u ki?n
    int longest = longestSequence(v);

    return 0;
}

