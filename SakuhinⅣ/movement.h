
//キーボードの種類
#define KEY_CODE_KIND		256	//256種類
#define CharaSpeed 2			//キャラクターのスピード


VOID MOVEMENT(VOID);				//キャラの移動関数
VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する関数

//キーボードの入力を取得
char AllKeyState[KEY_CODE_KIND] = { '\0' };		//すべてのキーの状態が入る
char OldAllKeyState[KEY_CODE_KIND] = { '\0' };	//すべてのキーの状態(直前)が入る


BOOL MY_KEY_DOWN(int);				//キーを押しているか、キーコードで判断する
BOOL MY_KEY_UP(int);				//キーを押し上げたか、キーコードで判断する
