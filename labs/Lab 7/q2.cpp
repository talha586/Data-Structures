//#include <iostream>
//#include <string>
//using namespace std;
//
//string decodeStringHelper(const string& s, int& i) {
//    string result = "";
//    while (i < s.size() && s[i] != ']') 
//    {
//        if (isalpha(s[i])) 
//        {
//            result += s[i];
//            i++;
//        }
//
//        else if (isdigit(s[i])) 
//        {
//            int k = 0;
//            while (i < s.size() && isdigit(s[i])) 
//            {
//                k = k * 10 + (s[i] - '0');
//                i++;
//            }
//            i++; 
//            string decodedPart = decodeStringHelper(s, i);
//            i++; 
//
//            for (int j = 0; j < k; j++) 
//            {
//                result += decodedPart;
//            }
//        }
//    }
//    return result;
//}
//
//string decodeString(const string& s)
//{
//    int i = 0;
//    return decodeStringHelper(s, i);
//}
//
//int main() {
//    string s1 = "3[a]2[bc]";
//    string s2 = "3[a2[c]]";
//    string s3 = "2[abc]3[cd]ef";
//
//    cout << decodeString(s1) << endl;  
//
//}
