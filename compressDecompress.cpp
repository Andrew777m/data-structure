#include<iostream>
#include "compressDecompress.h"
using namespace std;
vector<int> compress(string input){
    unordered_map <string, int> t;
    for(int i = 0; i < 256; i++){
        string ch = "";
        ch += char(i);
        t[ch] = i;
    }

    string A = "", B = "";
    A += input[0];
    int code = 256;
    vector<int> output;
    for(int i = 0; i < input.length(); i++){
        if(i != input.length() - 1){
            B += input[i+1];
        }
        if(t.find(A + B) != t.end()){
            A += B;
        } else {
            output.push_back(t[A]);
            t[A + B] = code;
            code++;
            A = B;
        }
        B = "";
    }
    output.push_back(t[A]);
    return output;
}


string decompress(vector<int> input)
{
    std::string output = "";
    unordered_map<int, string> t;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        t[i] = ch;
    }
    int o = input[0], r;
    string str = t[o];
    string B = "";
    B += str[0];
    output += str;
    int count = 256;
    for (int i = 0; i < input.size() - 1; i++) {
        r = input[i + 1];
        if (t.find(r) == t.end()) {
            str = t[o];
            str = str + B;
        }
        else {
            str = t[r];
        }
        output += str;
        B = "";
        B += str[0];
        t[count] = t[o] + B;
        count++;
        o = r;
    }
    return output;
}
