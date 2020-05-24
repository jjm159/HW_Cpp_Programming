#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <deque> // cut, paste의 복사 버퍼. 스택으로 사용!
#include <algorithm>
using namespace std;


class FakeFS {
	int CMDCONST;
	vector<bool (FakeFS::*)()> executeCommand;
	enum { ADD = 0, LS, CD, CUT, COPY, PASTE, RM, EXIT };
	const vector<string> cmdString { "add", "ls", "cd","cut","copy","paste","rm","exit" };
	vector<string> dirList{"/"};
	string cwd = "/";
	string inputCmd;
	string inputDir;
	vector<string> copyList;
public:
	FakeFS():CMDCONST(-1) {
		executeCommand.push_back(&FakeFS::add);
		executeCommand.push_back(&FakeFS::ls);
		executeCommand.push_back(&FakeFS::cd);
		executeCommand.push_back(&FakeFS::cut);
		executeCommand.push_back(&FakeFS::copy);
		executeCommand.push_back(&FakeFS::paste);
		executeCommand.push_back(&FakeFS::rm);
		executeCommand.push_back(&FakeFS::exit);
	}
	void reset() { inputCmd.clear(); inputDir.clear();  }
	const string& getCwd() const { return cwd; }
	int commandParser (const vector<string> & tokens ){
		inputCmd = tokens[0];
		if( tokens.size() > 1) inputDir = tokens[1];	
		for(int i = 0 ; i< cmdString.size()  ; i++) { 
			if(tokens[0] == cmdString[i]) return i;	
		}
		return -1;
	}
	bool readCLI(const vector<string>& tokens) {
		if( (CMDCONST=commandParser(tokens)) == -1) return false;
		return true;
	}
	bool executeCLI() {
		return (this->*executeCommand[CMDCONST])();
	}

	// 현재 디렉토리안에 있는 녀석들 인덱스 리스트 반환.
	const vector<int> findCwdIndexList(){
		vector<int> findList;
		for(int i = 0 ; i< dirList.size(); i++){
			if(dirList[i].find(cwd) == 0){ // 찾음.
				findList.push_back(i);
			}
		}
		return findList;
	}
	// 같은 이름 있나 검사.
	bool hasSameName(const vector<int>& indexList) {
		for( auto& i : indexList){
			if(dirList[i] == cwd + inputDir) return true; 
		}
		return false;
	}
	bool add() {
		if(inputDir.empty()){
			cout << "이름을 알려주세요" << endl;
			return false;
		} else if( inputDir[0] == '/' ) {
			cout << "절대경로는 지원하지 않아요." << endl;
			return false;
		}
		// 현재 디렉토리 인덱스 리스트를 얻고, 그 안에 같은게 있나 검사한뒤, 
		if(!hasSameName(findCwdIndexList())) { // 같은 이름 없으면 추가.
			dirList.push_back(cwd+inputDir);
			sort(dirList.begin(), dirList.end());	
			return true;
		}
		cout << "같은 이름 존재" << endl;
		return false;
	}
	bool ls() {
		if(!inputDir.empty()){
			cout << "명령어만 입력해주세요" << endl;
			return false;
		}
		auto indexList = findCwdIndexList();
		for( auto& i: indexList) {
			if(dirList[i] == cwd) continue; // 디렉토리 자체는 출력 안함.
			string str = dirList[i];
			str.erase(0, cwd.size());
			cout << str << endl;
		}
		return true;
	}
	bool cd() { // 있는지 체크하고, cwd변경 // 파일이름이 인자면 이동 불가.
		// 절대경로는 /로 시작.
		if(inputDir[0] == '/') {
			if( dirList.end() == find(dirList.begin(), dirList.end(), inputDir)){
				cout << "해당 경로는 존재하지 않아요" << endl;
				return false;
			}
			cwd = inputDir;
			return true;
		}
		// 상대경로.
		if(inputDir.empty()) {
			cout << "이름을 알려주세요" << endl;
			return false;
		} else if( inputDir.back() != '/') {
			cout << "파일 말고 디렉토리 이름을 알려주세요" << endl;
			return false;
		} else if( inputDir == "../") {
			string str = cwd;
			str.pop_back();
			string key ("/");
			int found = str.rfind(key);
			if (found >= 0){
				for(int i = cwd.size()-1 ; i > found; i--){
					cwd.pop_back();
				}
				return true;
			}
			else  // 찾은게 루트라면. cwd 변경 없음.
				return true;
		} else if (hasSameName(findCwdIndexList())){ 
			cwd = cwd+inputDir;
		} else { 
			cout << "해당 이름을 가진 디렉터리가 없어요" << endl;
			return false;
		}
		return true;
	}
	bool cut() {
		if(inputDir.empty()){
			cout << "이름을 알려주세요" << endl;
			return false;
		} else if( inputDir[0] == '/' ) {
			cout << "절대경로는 지원하지 않아요." << endl;
			return false;
		}
		if(hasSameName(findCwdIndexList())) { // 같은 이름 있다. 자른다.
			copyList.clear();
			for(int i = 0; i< dirList.size();i++){
				if(0 == dirList[i].find(cwd + inputDir)) {
					copyList.push_back(dirList[i]);
				}
			}
			if(inputDir.back() != '/') { // file인 경우.
				copyList.erase(copyList.begin()+1, copyList.end());	
			}
			for(int i = 0 ; i< copyList.size(); i++){
				copyList[i].erase(0,cwd.size());
			}
			auto size = dirList.size();
			for(int i = 0; i< size;i++){
				if(!dirList[i].find(cwd + inputDir)) {
					dirList.erase(dirList.begin()+i);
					i--; size--;
				}
			}
			return true;
		}
		cout << "현재 디렉토리에 해당 이름을 가진 것은 존재하지 않아요" << endl;
		return false;
	}
	bool copy() {
		if(inputDir.empty()){
			cout << "이름을 알려주세요" << endl;
			return false;
		} else if( inputDir[0] == '/' ) {
			cout << "절대경로는 지원하지 않아요." << endl;
			return false;
		}
		if(hasSameName(findCwdIndexList())) { // 같은 이름 있다. 자른다.
			copyList.clear();
			for(int i = 0; i< dirList.size();i++){
				if( 0 == dirList[i].find(cwd + inputDir) ) {
					copyList.push_back(dirList[i]);
				}
			}
			if(inputDir.back() != '/') { // file인 경우.
				copyList.erase(copyList.begin()+1, copyList.end());	
			}
			for(int i = 0 ; i< copyList.size(); i++){
				copyList[i].erase(0,cwd.size());
			}
		} else {
			cout << "현재 디렉토리에 해당 이름을 가진 것은 존재하지 않아요" << endl;
		}
		return true;
	}
	bool paste(){
		if (!inputDir.empty()) {
			cout << "명령어만 입력해주세요" << endl;
			return false;
		}
		if(copyList.empty()){
			cout << "복사된 것이 없어요" << endl;
			return false;
		}
		vector<int> indexList = findCwdIndexList();
		for(auto &i : indexList) {
			if(dirList[i] == cwd+copyList[0]){
				cout << "같은 이름을 가진 것이 존재합니다." << endl;
				return false;
			}
		}		
		for(int i = 0 ; i< copyList.size(); i++){
			dirList.push_back(cwd + copyList[i]);
		}
		sort(dirList.begin(), dirList.end());
		return true;
	}
	bool rm() {
		if(inputDir.empty()){
			cout << "이름을 알려주세요" << endl;
			return false;
		} else if( inputDir[0] == '/' ) {
			cout << "절대경로는 지원하지 않아요." << endl;
			return false;
		} 
		if(hasSameName(findCwdIndexList())) { // 같은 이름 있다. 자른다.
		//	const vector<int>& indexList = findCwdIndexList();
			auto size = dirList.size();
			for(int i = 0; i< size;i++){
				if(0 == dirList[i].find(cwd + inputDir)) {
					dirList.erase(dirList.begin()+i);
					i--; size--;
				}
			}
		} else {
		cout << "현재 디렉토리에 해당 이름을 가진 것은 존재하지 않아요" << endl;
			return false;
		}
		return true;
	}	
	bool exit() {
		if (!inputDir.empty()) {
			cout << "명령어만 입력해주세요" << endl;
			return false;
		}
		cout << "프로그램을 종료합니다." << endl;
		::exit(0);
	}
};


void promptCLI(vector<string>& tokens);

int main() {
	FakeFS fs;
	vector<string> tokens;
	string cwd;
	while(1) {
		cwd = fs.getCwd();
		cout << cwd << "> ";
		tokens.clear();
		promptCLI(tokens);
		if(tokens.size() >0 && tokens.size() <3) 
			fs.readCLI(tokens) && fs.executeCLI();
		else if (tokens.size() == 0)
			cout << "명령어를 입력하세요." << endl;
		else if (tokens.size() > 2)
			cout << "명령어가 너무 많아요" << endl;
		fs.reset();
	}
	return 0;
}

void promptCLI(vector<string>& tokens){
	string command;
	string ctok;

	getline(cin, command);
	stringstream sscmd(command);
	while(getline(sscmd, ctok, ' ')) {
		tokens.push_back(ctok);
	}
	return ;
}
