#include <bits/stdc++.h>
using namespace std;

/*
Strings have a unique property that makes them highly useful for solving various problems.
In programming, particularly in languages like C, strings are stored as sequences of characters, where each character is represented
by its ASCII value. These characters are stored in contiguous memory locations. This contiguous nature of string storage allows for
efficient manipulation and problem-solving. Understanding and leveraging this property can help tackle many string-related challenges,
making the study of string contiguity particularly interesting and important.

If we used a character array and wanted to track the frequency of each character, we could store these frequencies using a hash map or
another data structure. However, since hash maps or trees do not store elements in sorted order, when traversing, the characters would
not be sorted. To print them in sorted order with their frequencies, we would need to sort the hash map or tree, which could lead to a
time complexity of O(N log N).

However, by leveraging the contiguous nature of string storage, where characters are stored in order, we can more efficiently obtain a
sorted sequence along with their frequencies. This approach significantly reduces the time complexity compared to the conventional
method. This optimization is a powerful technique that allows us to solve the same problem with much greater efficiency.
*/

void printAlphabetFrequencies(string str) {
    int count[26] = { 0 };
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i] - 'a']++;
        /* Lets say g is the 7th element and we want to count the frequency of that 7th element, so we would need the right index of
        the character in the array and we could get it by using contiguous nature. g's value 104 - a's value 97 = 7 which is the place
        of 'g' and now we increase it's count in count array. By this way we got the frequency in Ø(n) and that too sort of stored in sorted order.  */
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
            cout << (char)(i + 'a') << " " << count[i] << endl;
    }
}

/*
Based on this algorithm/method too, we can sort the string in O(n). It's called counting sort. How?
We just now from line 31, instead of just printing the charater with frequency, we can just printthe charater*frequency number of times
in loop and that's how we print the given string in sorted order.
*/

int main() {
    string str;
    cin >> str;

    printAlphabetFrequencies(str);

    return 0;
}

/*
geeksforgeeks
mann
*/

