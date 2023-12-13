#include <vector>
#include<bits/stdc++.h>

int longestSequence(const std::vector<std::pair<int, int>>& v) {
    // S?p x?p m?ng theo ph?n t? th? hai c?a m?i c?p
    std::sort(v.begin(), v.end(),  {
        return a.second < b.second;
    });

    int longest = 0;  // �? d�i c?a chu?i d�i nh?t
    int length = 0;   // �? d�i c?a chu?i hi?n t?i
    int end = -1;     // K?t th�c c?a chu?i hi?n t?i

    // Duy?t qua m?ng
    for (const auto& pair : v) {
        // N?u c?p s? hi?n t?i kh�ng thu?c chu?i hi?n t?i, k?t th�c chu?i hi?n t?i
        if (pair.first > end) {
            // C?p nh?t d? d�i c?a chu?i d�i nh?t n?u c?n
            longest = std::max(longest, length);
            // B?t d?u m?t chu?i m?i
            length = 1;
            end = pair.second;
        } else {
            // N?u c?p s? hi?n t?i thu?c chu?i hi?n t?i, tang d? d�i c?a chu?i
            length++;
        }
    }

    // Ki?m tra m?t l?n n?a sau khi duy?t xong m?ng
    longest = std::max(longest, length);

    return longest;
}

int main() {
    // T?o m?t vector ch?a c�c c?p s?
    std::vector<std::pair<int, int>> v = {{1, 5}, {2, 3}, {4, 1}, {6, 4}};

    // T�nh d? d�i c?a chu?i d�i nh?t th?a m�n di?u ki?n
    int longest = longestSequence(v);

    return 0;
}

