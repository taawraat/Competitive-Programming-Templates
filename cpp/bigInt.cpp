#include<bits/stdc++.h>
using namespace std;

// string addition
string sum(string num1,string num2){
    int len1 = num1.length();
    int len2 = num2.length();
    string ans;
    bool end1 = false, end2 = false;
    int i = 0, carry = 0;
    
    // will break if num1 and num2 ends
    for( ;!end1 || !end2; ){
        // iterating in reverse order
        if(len1) len1--;
        if(len2) len2--;

        // adding num1 and num2
        int temp = (num1[len1]-48) + (num2[len2] - 48);
        temp += carry;

        carry = temp / 10;
        ans.push_back((temp % 10)+48);
        i++;

        // initializing to 0 if num1 or num2 ends
        if(!len1){ end1 = true; num1[len1] = '0'; }
        if(!len2){ end2 = true; num2[len2] = '0'; }
    }

    if(carry) ans.push_back(carry+48);
    reverse(ans.begin(), ans.end());
    return ans;
}

//str multiplication of a*b
string strMultiplication(string a, string b){
    string ans = "0";
    string postZeros = "";
 
    for(int i = b.length()-1; i >= 0; i--){
        int carry = 0;
        string current;

        if(b[i] == '0')
            current.push_back('0');
        else
            for(int j = a.length()-1; j >= 0; j--){
                int S1_j = a[j] - 48;
                int S2_i = b[i] - 48;
                int temp = (S1_j * S2_i) + carry;
                carry = temp/10;
                // if(current != "0")
                    current.push_back((char)((temp%10) + 48));
            }
        if(carry) current.push_back(carry+48);
        reverse(current.begin(), current.end());
        current += postZeros;
        ans = sum(ans,current);
        
        postZeros += "0";
    }
 
    return ans;
}

// driver code
int main(){
    // sample test case
    cout << sum("123456","789197699") << endl;
    cout << strMultiplication("123456","789197699") << endl;
}
