#include <iostream>
using namespace std;
const int MAX = 100;
class String {
private:
    char str[MAX];
public:
    String();
    String(const char*);
    void Insert(int pos, char ch);
    void Del(int pos);
    void Print();
    void Println();
    int Search(char ch);
    String SubString(int start, int end);
    void ToUpper();
    void ToLower();
    int Length();
    bool Search_string(string s);
    String SubStringusr(int start, char delim);
    String operator + (String st) const;
};
String::String() {
    str[0] = '\0';
}
String::String(const char* s) {
    int i = 0;
    for (; s[i]; i++) {
        str[i] = s[i];
    }
    str[i] = '\0';
}
// inserts a character at given position position
void String::Insert(int pos, char ch) {
    // Shift elements to right
    int i = MAX - 1;
    for (; i > pos; i--)
        str[i] = str[i - 1];
    str[i] = ch;
}
// deletes an element from the given position position
void String::Del(int pos) {
    // skip to the desired position
    int i = pos;
    for (; str[i]; i++)
        str[i] = str[i + 1];
}
// searches String for a given element character
int String::Search(char ch) {
    // Traverse the String
    int i = 0;
    for (; i < MAX; i++) {
        if (str[i] == ch) {
            return i; // return character position
        }
    }
    return -1;
}
// Returns Substring
String String::SubString(int start, int total_characters) {
    String temp;
    int i = start;
    int end = start + total_characters;
    for (; i < end && i < MAX; i++) {
        temp.str[i - start] = str[i];
    }
    temp.str[i - start] = '\0';
    return temp;
}
// displays the contents of a String
void String::Print() {
    cout << str;
}
void String::Println() {
    cout << str << endl;
}
void String::ToUpper() {
    string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    int i = 0;
    for (; str[i]; i++) {//loop through all str
        for (int j = 0; j < 27; j++) {//loop through all of temp
            if (int(str[i]) == (int(temp[j]) + 32)) {//if ascii difference is found
                str[i] = temp[j];//replace str[i] with temp of ascii difference
            }
        }
    }
    str[i] = '\0';
}
void String::ToLower() {
    string temp = "abcdefghijklmnopqrstuvwxyz ";
    int i = 0;
    for (; str[i]; i++) {       //looping through size of str
        for (int j = 0; j < 26; j++) {  //looping through all alphabets in temp
            if (int(str[i]) == (int(temp[j]) - 32)) { //the difference of upper/lower in ascii if found
                str[i] = temp[j];  //replace str[i] with temp's lower digit of same ascii 
            }
        }
    }
    str[i] = '\0';  //end the string 
}
int String::Length() {
    int i;
    for (i = 0; i < sizeof(str); i++) { //loop through the size of str
        if (str[i] == '\0') {           //return i if string ends
            return i;
        }
    }
}
bool String::Search_string(string s) {
    String temp;                      //make object temp to access temp.str
    for (int i=0; i<sizeof(str-1); i++) { // (str-1) to accommodate for temp.str[i+1] 
        temp.str[i] = str[i];         //copy the data of str to temp one by one
        temp.str[i + 1] = '\0';       //create end string as string s has one 
        if (s == temp.str ) {         //check if s = temp.str every time temp gets a new character
            return true;              //end function if that is the case
        }  
    }
    return false;                    // end function of if "if" doesn't find the match
}

String String:: SubStringusr(int start, char delim){
    String temp;                    // make object temp
    for (int i = start; i < sizeof(str); i++) {  
        temp.str[i-start] = str[i];  // accommodate for the user defined start
        if (str[i] == delim) {      //if delim is found 
            temp.str[i - start] = '\0'; //for not including the delim character
            return temp;
        }
    }
}
String String :: operator + (String st) const {
	String temp;
	int i, j;
	for (i = 0; i < sizeof(str); i++) {
		temp.str[i] = str[i]; //copy the 1st string to temp
		if (str[i] == '\0') {
			break;              // break the loop when string 1st string is over
		}
	}
	for (j = 0; j < sizeof(st.str); j++) {
		temp.str[i + j] = st.str[j]; // copy the data of second string starting from 
	}                                // where the last string ended
	return temp;
}
int main()
{
    String to_seprate ("Sunday, August 14, 2022 14:15:16");
    String seprated_weekday = to_seprate.SubStringusr(0, ',');
    String seprated_month =   to_seprate.SubStringusr(8, ' ');
    String seprated_date =    to_seprate.SubStringusr(15, ',');
    String seprated_year =    to_seprate.SubStringusr(19, ' ');
    String seprated_hours =    to_seprate.SubStringusr(23, ':');
    String seprated_minutes = to_seprate.SubStringusr(27, ':');
    String seprated_seconds = to_seprate.SubStringusr(30, '\0');
    cout << "string = "; to_seprate.Println();
    cout << "separated weekday = "; seprated_weekday.Println();
    cout << "separated month = "; seprated_month.Println();
    cout << "separated date = "; seprated_date.Println();
    cout << "separated year = "; seprated_year.Println();
    cout << "separated hours = "; seprated_hours.Println();
    cout << "separated minutes = "; seprated_minutes.Println();
    cout << "separated seconds = "; seprated_seconds.Println();
    //code for checking concatenation
    String str1("string1"); String str2("string2");
    String concat = str1 + str2;
    cout << "concatenating strings: "; concat.Println();
    //code for checking to upper function
    concat.ToUpper(); cout << "converted to upper : "; concat.Println();
    concat.ToLower(); cout << "converted to lower: "; concat.Println();
    cout << "length of the string: "; cout <<concat.Length()<<endl;
    //cout << "is \"string1\" in the string?"; 
    cout << endl;
    cout <<concat.Search_string("str");
    return 0;
    
}