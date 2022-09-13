# Fake-Shell

## 開發環境
- 使用的程式語言: C++
- 虛擬機器軟體 : Oracle VM VirtualBox
- 作業系統 : Ubuntu 18.04.05(64bit)

## 說明
此為用C++所撰寫之偽造Shell，會先輸出由主機名稱,目前所在目錄與使用者名稱所組成的偽造prompt，再依據使用者所輸入的命令進行對應動作

## 使用流程
1. 編譯 : g++ fakeshell.cpp -o out 
2. 執行 : ./out
3. 螢幕顯示偽造提示字元，格式為 	  
	{HOSTNAME} : {PWD} 
    {USERNAME} > 
	請使用者開始輸入命令(e.g. ls, touch, less......)，結束程式之命令為exit

## 程式驗證結果

