::/* TOPPERSカーネルテストスイート
:: * 
:: *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
:: * 
:: *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation
:: *  によって公表されている GNU General Public License の Version 2 に記
:: *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
:: *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
:: *  利用と呼ぶ）することを無償で許諾する．
:: *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
:: *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
:: *      スコード中に含まれていること．
:: *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
:: *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
:: *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
:: *      の無保証規定を掲載すること．
:: *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
:: *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
:: *      と．
:: *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
:: *        作権表示，この利用条件および下記の無保証規定を掲載すること．
:: *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
:: *        報告すること．
:: *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
:: *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
:: * 
:: *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
:: *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
:: *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
:: *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
:: */

@echo off
:::--- TEMP_LOG=1 は各テスト項目の実行時作成される temp.log を
:::--- 削除せず、保存しておく設定。
:::--- この設定を削除すると、temp.log も削除される
SET TEMP_LOG=1

IF "%O_PATH%"=="" SET O_PATH=%PATH%

IF "%1"=="help" GOTO ERROR0
IF "%1"=="" GOTO ERROR0

SET DRIVE_K=
SET FULL_TEST=_fi4
IF "%1"=="j" SET FULL_TEST=_jsp

IF "%1"=="j" SET DRIVE_K=C:\TOPPERS\jsp141
IF "%1"=="f" SET DRIVE_K=C:\TOPPERS\fi4
IF "%DRIVE_K%" == "" GOTO ERROR1

subst k: /D >nul
subst k: %DRIVE_K%
if errorlevel 1 goto ERROR_K
echo ドライブ Ｋ：を %DRIVE_K% に設定しました。

IF "%GHS_SH%"=="" SET GHS_SH=C:\green\ide\sh.501
IF "%CYGWIN%"=="" SET CYGWIN=C:\cygwin\bin
IF "%MINGW%"=="" SET MINGW=C:\mingw\bin
IF "%CFG%"=="" SET CFG=K:\cfg
SET PATH=%O_PATH%%GHS_SH%;%MINGW%;%CYGWIN%;%CFG%;
:echo PATHにGHS,CYGWIN,CFGを追加しました。

SET DRIVE_T=C:\TOPPERS\std_test
IF "%DEFAULT_BLD%"=="" SET DEFAULT_BLD=%DRIVE_T%\test\default%FULL_TEST%.bld

IF NOT "%2"=="bld" GOTO END
IF NOT "%3"=="-all" GOTO N3
IF exist %CFG%\cfg.exe GOTO N3
del library\libkernel.a 2>nul
pushd %CFG%
make depend
make cfg
popd

:N3
echo %1のカーネルを作成します。
pushd library
build -noreasons %3 default.bld
popd
GOTO END

:ERROR_K
echo ドライブ Ｋ：が使用できません。
GOTO END

:ERROR1
echo.
echo setup.bat のパラメータが間違いです
:ERROR0
echo "setup j|f [bld [-all]]"
echo.
:END
