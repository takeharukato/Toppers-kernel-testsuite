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
if "%BAT_DIR%" == "" goto ERROR
SET TEST_DIR=%BAT_DIR%test_case\
::-----------コンフィギュレータのエラー未検出の結果表示選択------::
::--- エラー未検出の結果を表示するときには No_Errors_Find=1 に変更---::
::SET No_Errors_Find=1
SET No_Errors_Find=
::-----------現在のワーキングディレクトリを保存-----------::
for /F  "tokens=1*" %%V in ('cd') do set CUR_DIR=%%V
cd %BAT_DIR%
if "%FULL_TEST%"=="_jsp" (
dir /B /S /ON test_case\%1\test.bat | sort > dir.tmp
) ELSE (
dir /B /S /ON test_case\%1\test?.bat | sort > dir.tmp
)
if "%2" == "clean" goto %2
if "%2" == "cleanlog" goto %2
if "%2" == "dumplog" goto %2

if "%2"=="" set output_auto_test="&3" 
if not "%2" == "" set output_auto_test=%CUR_DIR%\%2

if not exist setup.bat goto ERROR
call setup.bat SET_ENV

::バッチファイルを呼び出したディレクトリとそのサブディレクトリの
::テストスイトを実行
echo ---auto test for μITRON4.0 (%DRIVE_K%)---- > %output_auto_test%
echo ---Time Stamp %DATE% %TIME%----- >> %output_auto_test%
echo.

for /F "tokens=* delims=" %%i in (dir.tmp) do call exec_auto.bat %%i %2 >> %output_auto_test%
echo ---Done %DATE% %TIME%---- >> %output_auto_test%
goto END

::::::::::中間ファイルを削除::::::::::
:cleanlog
set output_auto_test="nul" 
echo Cleaning log files

for /F "tokens=* delims=" %%i in (dir.tmp) do call exec_auto.bat %%i %2
goto END

:clean
set output_auto_test="nul" 
echo Cleaning intermediate files

for /F "tokens=* delims=" %%i in (dir.tmp) do call exec_auto.bat %%i %2
build -clean -noprogress default.bld 2>nul
goto END

:dumplog
set output_auto_test=%CUR_DIR%\%3.log
echo Dump log into %CUR_DIR%\%3.log
if exist %output_auto_test% del %output_auto_test% > nul
dir /B /S /ON test_case\%1\test.log | sort > dir.tmp
for /F "tokens=* delims=" %%i in (dir.tmp) do call dumplog.bat %%i >> %output_auto_test%
goto END

:ERROR
echo ***Error(s) occured while performing the test***

:END
cd %BAT_DIR%
if exist setup.bat call setup.bat DEL_ENV
del dir.tmp 2>nul
set TEST_DIR=
cd %CUR_DIR%
set CUR_DIR=
set output_auto_test=
