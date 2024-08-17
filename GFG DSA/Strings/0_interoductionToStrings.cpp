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

/*
In majority of c/c++, string library, it relies on putting the '\0' at the end of the string/char array.****
So if you do sizeof(str) => str.length() + 1, because of the '\0' occupancy.
After the input charaters are filled up in character array, if there's more size of the character array, it keep on putting the '\0' till the end.
Also if you decide to create a character array with single quotes, you then must have to insert '\0' manually at the end or its will give sagmentation fault.
So better to just use double quote instead of single one[C-Style string] to not be in such mess. E.g: (if we still want to use array) int char str[] = "gfg";
*/

/* Most commonly used C-Style string funtions:
strlen(str);
// Scans till it finds '\0' and print the value/size.

strcmp(s1,s2);
//Compares two string lexographically, so is the first string is greater than the second, its returns positive value. If lexographically same, returns 0. If s1<s2 lexo, return negative value.

strcpy(s1,s2);
// Copies the string s2 to the s1. s1 is replaced full by s2

But its better to use C++-Style string function than to use the C-Style string functions. And way less problems. Just like vectors to array

Should go through the gfg video to get the base more clear. "Strings in C++" video.
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

