#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void reading(ifstream& f, string &s)
{
	string ss;

	while(getline(f,ss))
	{
		s = s + ss+'\n';
	}
}

void replace_long_words(string& s, int max_len, string change, string const &liters)//max_len - length of words needed to replace
{
	string ss 	= s; //temporary string
	s 			= "";

	int last_pos 			= 0;											//pointer on last search position
	int first_liter_pos 	= ss.find_first_of(liters, last_pos); 			//firs liter
	int first_not_liter_pos	= ss.find_first_not_of(liters, first_liter_pos);//first not liter AFTER liters
	int word_len 			= first_not_liter_pos - first_liter_pos; 		//kiddin me?

	while ((first_liter_pos != string::npos) && (first_not_liter_pos != string::npos))
	{
		if (word_len <= max_len)
		{
			s = s + ss.substr(last_pos, (first_liter_pos - last_pos) + word_len);
		}
		else
		{
			s = s + ss.substr(last_pos, first_liter_pos - last_pos) + change;
		}

		last_pos			= first_not_liter_pos;
		first_liter_pos 	= ss.find_first_of(liters, last_pos);
		first_not_liter_pos	= ss.find_first_not_of(liters, first_liter_pos);
		word_len 			= first_not_liter_pos - first_liter_pos;
	}

	s = s + ss.substr(last_pos, ss.length()-last_pos);
}

void marks_right_frame(string& s, string marks, char frame)//max_len - length of words needed to replace
{
	string ss = s;
	int last_pos = 0;

	while (ss.find_first_of(marks, last_pos)!=string::npos)
	{
		int first_mark_pos = ss.find_first_of(marks, last_pos);
		int start_frame_pos = first_mark_pos;

		for(; ((start_frame_pos>0)&&(ss[start_frame_pos-1]==frame)); start_frame_pos--);
		
		ss.erase(start_frame_pos, first_mark_pos - start_frame_pos);
		ss.insert(start_frame_pos+1, 1, frame);
		
		last_pos = start_frame_pos+2;//+1 for mark and +1 for space
	};

	s = ss;
}

vector<string> devide_to_substrings(string& s, int max_len, string const &liters)
{
	string ss = s;
	int last_pos = 0;
	vector<string> v;

	while(ss.length() - last_pos >= max_len)
	{
		string ns = "";
		
		int first_liter_pos 	= ss.find_first_of(liters, last_pos);
		int first_not_liter_pos = ss.find_first_not_of(liters, first_liter_pos);

		if (first_not_liter_pos!=string::npos)
		{
			if (ns.length()+ss.substr(last_pos, first_not_liter_pos).length()<max_len)
			{
				ns = ns + ss.substr(last_pos, first_not_liter_pos);
				cout<<ns<<endl;
				last_pos 			= first_not_liter_pos;
				first_liter_pos 	= ss.find_first_of(liters, last_pos);
				first_not_liter_pos = ss.find_first_not_of(liters, first_liter_pos);
			} 
			else
			{
				v.push_back(ns);
			}
		}
	};

	v.push_back(s.substr(last_pos,ss.length()-last_pos));
}

int main()
{
	ifstream f; 
	f.open("text.txt");

	string liters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string s;
	reading(f,s);
	cout<<s<<endl;

	replace_long_words(s, 0, " ", "\t\n");
	marks_right_frame(s, ":;?!,", ' ');
	replace_long_words(s, 10, "WOW!", liters);

	vector<string> v = devide_to_substrings(s, 40, liters);
	cout<<s<<endl;
	
	f.close();
	return 0;
}