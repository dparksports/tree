#include <bits/stdc++.h>
#include <map>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// N = vector a
// M = vector b
// O(N) + O(M) + O(k)
// O(N + M), N > M or M > N, ==> N* 2
// O(N * 2)   => O(N)

// map[key] = value
// hash function key calc
// element hash insertion ==>  
// double-linked list > insertion on binary tree.
// insertion use case vs look use case
// map case ==> lookup use case.
// O(k)
// O (log N) == binary tree
// fixed array with hash value of a key is the index.
// calc a hash value (key) ==> index
// array[index]  ==> O(k)

// O (log N) =  binary insertion => one element insertion
// N * O (log N)
// O (N log N)

// O (N) + O (N)  ==> O (N)
// O (N)

// vector contains an element which is not int?
// 
 
 // A = [1 2] B = [3]
 // A = [1 2] B = [2 2]
 // B[0] = 2, B[1] = 2
 // iterating B vector from b.begin() to b.end()
 // 
// Complete the b_in_a function below.


bool b_in_a(vector<int> a, vector<int> b) {
    map<int, int> counts;
    map<int, int> numbers;
    for (int i = 0; i < a.size(); i++) {
        int key = a[i];
        int value = a[i];
        numbers[key] = value;
        counts[key] += 1;
    }
    
    // iterating all elements from the index 0 (begin) to the index (M-1) (end)
    for (int j = 0; j < b.size(); j++) {
        int element = b[i];
        int key = b[i];  // vector b = vector<int>
        // 
        if (numbers[key] != element) {
            return false;
        } else {
            counts[key] -= 1;
        }
    }
    
    for (int k=0; k < counts.size(); k++) {
        if (counts[k] != 0) {
            return false;
        }
    }
    
    return true;
}

operator !=(int &a, string& b ) {
    
}


class HashMap {
    private:
    int N = 100;
    vector<int> mapping(0, N); // hash index to index

    protected:
        
        // return a hash key between 0 to N-1
        // gurantee whatever value [0, M] --> a unique hash value.
        // eg) hashFunction(10) != hashFunction(a), a != 10, a E [0, M)
        // O(k) = performance guranteee
    int hashFunction(int& value) {
        
    }
    
    
    public:
    
    HashMap() {
        
    }
    
    ~HashMap() {
        
    }
    
    
    int operator[] (int& a) {
        // index between 0 and N-1
        // value itself is a.
        int hashKey = hashFunction(a);
        mapping[hashKey] = a;
    }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    string b_count_temp;
    getline(cin, b_count_temp);

    int b_count = stoi(ltrim(rtrim(b_count_temp)));

    vector<int> b(b_count);

    for (int i = 0; i < b_count; i++) {
        string b_item_temp;
        getline(cin, b_item_temp);

        int b_item = stoi(ltrim(rtrim(b_item_temp)));

        b[i] = b_item;
    }

    bool res = b_in_a(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
