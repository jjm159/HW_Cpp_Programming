
// 제출용 파일은 주석 다 지우고 깔끔하게. 
// 이 원본 유지해서 깃헙에 올리고 나중에 수정합세.



// 테스트 한번만 더 해보고 로깅 삭제하기.
// Random으로 한번, Static으로 한번. 동적메모리 해제 되는지 까지.



/*
나중에 확장. - 확장성있는 게임을 만들게 되면 new/delete을 많이 쓰게될것.
지금은 stack으로 충분. 
1. 유저 수 제한 풀기
2. 보드판 제한 풀기.
3. 네트워크. 서버가 연산처리, 클라이언트는 입출력만.
4. 모바일이나 웹으로 그래픽하게.
*/

// 특수 점수 . 7은 2점. 
// 예외 처리 . -> 같은거 선택 하면 

#include <iostream>
#include <string>
#include <cstdlib> // rand, srand
#include <ctime> // time 
using namespace std;

// user information management
class User {
    int score;
    //const int PLUS_SCORE_QUANTITY = 1; // 점수 향상 정도. 몇점씩 올르냐.
    //int user_number;  // 생성된 유저 숫자, 유저 객체 생성시 1증가.
    int USER_IDENTITY; // turn 확인시 사용. // 배열로 사용하면서 이게 필요없어짐.
    // 그냥 일단은 지금은 p1 p2 딱 정해서 하자. 나중에 확장하자. 
public:
    User() {} // 밑에, 기본(디폴트) 생성자가 아닌 생성자가 존재하기 때문에, 기본생성자를 만들어야, 기본생성자가 필요한 객체를 생성할 수 있다.
    User(int id): score(0), USER_IDENTITY(id) {
        cout << "My Id is " << USER_IDENTITY << endl;
    }
    void plusScore(int selectedCard){ 
        // 7을 선택하면 2점 증가. 
        if( selectedCard == 7 ){
            score += 2;    
            return;
        }
        // 7이 아니면 1점 씩 증가. 
        score += 1;
        return;
    }
    string getId() { 
        string pID = "P";
        return pID + to_string(USER_IDENTITY);
    }
    int getScore() { return score; }
};
//int User::turn = 0;


class CardLocation {
    int mRow1, mCol1, mRow2, mCol2;
public:
// 숫자 넣어주면, 좌표로 환산해서 멤버변수에 할당하는 함수.
void extractCoordinate(int input1, int input2){
    mRow1 = (input1 / 10) - 1;
    mCol1 = (input1 % 10) - 1;
    mRow2 = (input2 / 10) - 1;
    mCol2 = (input2 % 10) - 1;
    cout << "This is extractFunction : " << mRow1 << " " << mCol1 << " " << mRow2 << " " << mCol2 << endl;
}
// 좌표 꺼내는 get함수 제공. 
    int row1() { return mRow1; }
    int col1() { return mCol1; }
    int row2() { return mRow2; }
    int col2() { return mCol2; }
};



// card information management
class CardManager {    // 카드를 관리하는 건 1차원적으로 생각하는 게 더 쉽다 생각.
// 정답지. 앞면. - 우선은 고정으로 하나 만듬. 
// 1차원으로 가지고 있자. 동적 메모리로. 
// 랜덤이면 셔플. 셔플함수. 
    int staticCardList[16];
    int *randomCardList; // 랜덤일 때만 할당 받아 사용. 
public:
    CardManager() { 
        cout << "card manager init - 이건 shuffle전에 나와야돼" << endl;
        // 고정 앞면 초기화. 
        for(int i = 0  ; i < 8 ; i++){
            staticCardList[i] = i+1;
        }
        for(int i = 8 ; i < 16 ; i++){
            staticCardList[i] = 16 - i;
        }
    }
    ~CardManager() {
        cout << "CardManager destructor" << endl;
        if(randomCardList != nullptr )
            delete[] randomCardList;
    }
    // 셔플 함수. // 셔플 판을 하나 가지고 있게. 
    void makeShuffleCard(){
        cout << "make shuffle card" << endl;
        randomCardList = new int[16]; // 랜덤 카드 리스트 생성.
        for(int i = 0 ; i < 16; i++){
            randomCardList[i] = staticCardList[i];
        }
        shuffle(); // 섞는다. 
    }
    // 랜덤 카드 리스트를 섞는다. 
    void shuffle() {
        cout << "shuffle" << endl;
        // 랜덤값 srand, rand 여기서만 사용하면 됨. 
        srand(time(NULL));
        int temp = 0;
        for ( int i = 0; i < 200 ; i++){
            int a = rand() % 16;
            int b = rand() % 16;
            temp = randomCardList[a];
            randomCardList[a] = randomCardList[b];
            randomCardList[b] = temp;
        }
        for(int i = 0; i< 16; i++){
            cout << randomCardList[i] << ' ';
        }
        cout << endl;
        
    }
    // 카드 앞면을 겟. 하는 함수. row,col 를 매개변수로 받고,
    // row,col를 1차원으로 '변환'해서 카드리스트 배열의 인덱스로 사용. 
    // 4*row + col -> 1차원으로 변환된 인덱스. 
    // 랜덤 보드판인지 고정 보드판인지 식별 필요. 여기 클래스 멤버로 상수 만들지 고민. 
    // 상수를 애초에 게임 시작할 때 고정해두면, 이 함수에 랜덤보드인지 아닌지 확인할 필요 없음. 
    int getCardNumber(int row, int col, int randomState) {
        int index = 4*row + col;
        if(randomState == 0){
            // no random card list
            return staticCardList[index];
        } else {
            // random card list
            return randomCardList[index];
        }   
    }
};
// game board printer - 카드매니저로부터 정보를 받아서 보드를 만들어 출력.
class BoardManager { // 화면을 구성해서 출력.  출력 함수를 만든다. 
    CardManager cardManager;
    int randomState = 0; // 0은 노 랜덤. 1은 랜덤 보드.
// 진행중인 판. 처음엔 모두 뒷면, 맞추면 앞면으로 바꿈.
// 0이면 x 출력. ?? char배열로 할까 숫자 배열로할까..?
    char gameBoard[4][4] = {
        {'x','x','x','x'},
        {'x','x','x','x'},
        {'x','x','x','x'},
        {'x','x','x','x'}
    };
public:
    BoardManager() {}
    // 게임 메니저에서 '랜덤이면' 이 함수 호출해서 랜덤 보드 사용할 거라고 보드 매니저에게 알려준다. 
    void setRandomeState() { 
        cout << "set random state call" << endl;
        randomState = 1; 
        cardManager.makeShuffleCard();
    } 

    // 출력 함수. ()
    void printBoard() {
        cout << "    1 2 3 4" << endl;
        cout << "--+--------" << endl;
        for(int row = 0 ; row< 4 ; row++ ){
            cout << " " << row + 1 << "|";
            for( int col = 0; col< 4; col++ ) {
                cout << " " << gameBoard[row][col] ;
            }
            cout << endl;
        }
    }
    void printBoard( CardLocation location ){
        // 선택 카드는 앞면으로 바꿔서 출력. 틀려도.
        cout << "    1 2 3 4" << endl;
        cout << "--+--------" << endl;
        for(int row = 0 ; row< 4 ; row++ ){
            cout << " " << row + 1 << "|";
            for( int col = 0; col< 4; col++ ) {
                if( (row == location.row1() && col == location.col1()) 
                    || (row == location.row2() && col == location.col2()) )
                    cout << " " << cardManager.getCardNumber(row, col, randomState);
                else
                    cout << " " << gameBoard[row][col] ;
            }
            cout << endl;
        }
    }
    // '정답이면' 출력 보드 수정. 매니저에서. 
    void flipCard(CardLocation location) {
        int row1 = location.row1();
        int col1 = location.col1();
        int row2 = location.row2();
        int col2 = location.col2();
        gameBoard[row1][col1] = '0' + cardManager.getCardNumber(row1, col1, randomState);
        gameBoard[row2][col2] = '0' + cardManager.getCardNumber(row2, col2, randomState);
    }
    int getSelectedCardNumber(CardLocation location) {
        return cardManager.getCardNumber(location.row1(), location.col1(), randomState);
    }
    bool isRight(CardLocation location){
        int firstCardNumber = cardManager.getCardNumber(location.row1(), location.col1(), randomState);
        int secondCardNumber = cardManager.getCardNumber(location.row2(), location.col2(), randomState);
        if( firstCardNumber == secondCardNumber){
            return true;
        } else {
            return false;
        }
    }

};

// game progress management
class GameManager {
    User p[2];

    CardLocation selectedLocation;

    BoardManager boardManager;

    int numberOfMatchedCardPair = 0; // 맞춘 짝의 개수.

    int turnCheckNumber; // 매턴마다 1씩 상승. 어떤 유저의 턴인지 확인할때 사용.
    // 2로 모듈러 연산. 0이면 p1, 1이면 p2.
public:
    GameManager(int isRandomBoard): turnCheckNumber(0) {
        p[0] = User(1);
        p[1] = User(2);
        // isRandomBoard 0이면 고정 판으로. 
        // 1이면 랜덤판으로 앞면 구성. 디폴트는 그냥 고정판. 
        if(isRandomBoard == 1){ // 랜덤 보드.
            cout << "isRnadomBoard == 1, so, call 'boardManager.setRandomeState();'"<< endl;
            boardManager.setRandomeState(); // 섞어주고, 랜덤 보드 사용한다고 선언.
        }
    }
    // 턴 끝날 때 이 함수 호출.
    void plusTurnNumber() {
        cout << "plusTurnNumber" << endl;
        turnCheckNumber++;
    }
    // 누구 턴인지 확인, 매 턴마다 0 1 0 1 ... 이 순으로 출력 됨.
    int checkTurn() {
        return turnCheckNumber % 2;
    }
    // 
    void gameStart() {
        // 배열 사용하면 조건문 안쓰고 턴마다 다른 유저로 출력,점수할당 가능.
        // 첫번째 턴. 이 때는 입력 안받고 바로 출력 후 시작. 
        cout << "Game Start," << " turn number is " << turnCheckNumber << endl;
        if(turnCheckNumber == 0){
            boardManager.printBoard();
            cout << p[0].getId() << "'s turn, choose two cards: ";
        }
        else 
            cout << p[checkTurn()].getId() << "'s turn, choose two cards: ";
        int input1, input2;
        cin >> input1 >> input2; // 문자가 입력 되면 무한루프 빠질수도! 
        cin.ignore(1000,'\n');
        getLocation(input1, input2);
        cout << "input value : " << input1 << input2 << endl;
        // 검사 후, 맞다 틀리다 출력 후 다음 턴으로! 
    }

// 입력값으로부터 좌표 추출. 
    void getLocation(int input1, int input2) {
        selectedLocation.extractCoordinate(input1, input2); 
        // 원래는 이런 함수도 예외 처리해서 여기서 잘못되었다는 걸 알려야함!
    }

    bool checkRight() {
        // 입력 값이 맞았는지 틀렸는지 확인, 
        if(boardManager.isRight(selectedLocation)){
            // ture -> 정답.
            boardManager.flipCard(selectedLocation);
            boardManager.printBoard(); // 원본이 바뀌어서, 그냥 출력하면 됨.
            p[checkTurn()].plusScore( boardManager.getSelectedCardNumber(selectedLocation) );
            numberOfMatchedCardPair++;
            cout << p[checkTurn()].getId() << " found a matching pair! ";
            cout << "P1's score: " << p[0].getScore() << ", "
                << "P2's score : " << p[1].getScore() << endl;
        } else { 
            // false -> 오답.
            cout << p[checkTurn()].getId() << " failed to find a matcning pair" << endl;
            boardManager.printBoard(selectedLocation); // 원본 안바꾸고 선택된 카드만 뒤집어서 출력.
        }
        // 8개 다 맞췄으면 true 반환해서 게임 종료시키기.
        if( numberOfMatchedCardPair == 8){
            cout << "Game finished. Final scores are P1: " << p[0].getScore() 
                << " and P2: " << p[1].getScore() << endl;
            return true;
        }
        return false;
    }
// 입력한 값이 정답인지 체크하는 건 이 클래스 몫. 
// 입력 값이 이미 존재하는 값을 건드렸는지, 범위 벗어났는지 에러처리도 이 클래스 몫.


    

    // 입력 받는 함수. - 여기서 입력값을 좌표로 분할 작업. 모듈러.
    // 입력 받고 바로 출력. 입력 값 추출해서 출력 이미지에 적용. 뒤집기.

};

// 예외처리 함수. 예외 메세지 출력. 변수가 필요하면 클래스로.
// 메세지를 넣어주면 그 메세지를 출력. 
void printErrorMessage(string errorMessage) {
    cout << errorMessage << endl;
    // 리턴 값으로 뭔가 메세지를 반환??? 할수도?
}

int main() {
// 1선택하면 랜덤 아님, 2선택하면 랜덤. 
    cout << "------ Card Match Game ------" << endl;
    cout << "Choose whether you use random or not." << endl;
    cout << " 1. Random Card  2. Fixed Card" << endl;
    cout << "-> ";
    int isRandomBoard = 0;
    cin >> isRandomBoard; // 일단 예외처리 ㄴㄴ 

// 게임 종료 키 설정.  언제든 그 키를 누르면 
// GameManager
// while문 1턴이 게임 한 턴. 
// 게임이 종료되면,  다시 게임을 
int endOrNot = 1;
    while(endOrNot){
        GameManager gameManager(isRandomBoard); 
        while(1) {
    // 여기서 gameManager의 함수들이 호출되면서 게임이 진행.    
    // 처음 시작
    // 보드 
    // 입력 - 이것도 매니저가 처리. 
            gameManager.gameStart();
    // 입력 확인 - 틀리고 맞는지 처리 후 어떻게?
             // 승리 판정. 
    // 승리 판정 후, 게임 종료 inner while 빠져 나가기. 
            if(gameManager.checkRight()){// 여기에 게임 종료됐는지 매니저 상태변수로 확인함수 호출. true false 반환.  
                break;
            }
            gameManager.plusTurnNumber();
        }
    // 여기로 빠져나오면 자동으로 gameManager객체가 소멸됨.
    // 그리고 리겜을 하게되면 다시 inner while문이 시작되고,
    // 다시 게임 메니저 메모리가 생성되면서 자동으로 초기화 됨. 
    // 여기서 게임 종료 or 리겜 묻기. 
        cout << "Game Over or not? If you end the game, input '0'(other number will retart the game.)" << endl;
        cout << "-> ";
        cin >> endOrNot;
    }
    return 0;
}
