//2019 카카오블라인드채용 기출

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer; 
	vector<pair<string, string>> output; //answer출력위해서 단어,ID값 저장
	map<string, string> data; //ID,nikname 매칭
	

	for (int i = 0; i<record.size();i++)
	{
		if (record[i][0] == 'E') //Enter일 경우
		{
			int j;
      string id,name;
			for (j = 6; record[i][j] != ' '; j++)
			{
				id += record[i][j];
			}
        
			for (int k = j + 1; k<record[i].size();k++)
			{
				name += record[i][k];
			}
			data[id] = name;
			output.push_back({"E",id });
		}
    
		else if (record[i][0] == 'L') //Leave
		{
      string id,name;
			for (int j = 6; j<record[i].size(); j++)
			{
				id += record[i][j];
			}
			output.push_back({ "L",id });
		}
    
		else if (record[i][0] == 'C') //Change
		{
      string id,name;
			int j;
			for (j = 7; record[i][j] != ' '; j++)
			{
				id += record[i][j];
			}
			for (int k = j + 1; k<record[i].size();k++)
			{
				name += record[i][k];
			}
			data[id] = name;
		}
	}
 
 //output 데이터 이용하여 출력.
	for (int i = 0; i<output.size();i++)
	{
		string result ;
        result += data[output[i].second] ;
		if (output[i].first == "E")
		{
			result += "님이 들어왔습니다.";
		}
		else if (output[i].first == "L")
		{
			result += "님이 나갔습니다.";
		}
		answer.push_back(result);
	}
	return answer;
}
