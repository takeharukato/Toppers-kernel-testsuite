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

cd %~p1
if not exist %1 goto END
if "%2" == "clean" goto CLEAN
if "%2" == "cleanlog" goto CLEANLOG

echo Running %~p1 >&3

::ログファイルに進行状況を書き込み
if not "%2" == "" echo Running %1

::タイムスタンプ
echo ---auto test for μITRON4.0 (%DRIVE_K%)---- > test.log
echo -----Running %~p1  %DATE% %TIME%----- >> test.log

if exist test.bat call test.bat > temp.log
if exist testx.bat call testx.bat > temp.log
GOTO ERROR_%ERRORLEVEL%

:ERROR_0
type temp.log | findstr "**** Step" >> test.log
type temp.log | find "****"
if not errorlevel 1 goto ERROR
type temp.log | find "---Reached Last" 
if errorlevel 1 goto ERROR
call %BAT_DIR%exec_auto.bat %1 clean
GOTO END

::エラーが発生した場合、エラーメッセージを出力
:ERROR_2
type temp.log | findstr "**** Step" >> test.log
:ERROR
echo Error(s) found
goto END

:ERROR_1
if "%No_Errors_Find%"=="" GOTO END
echo Error(s) "エラーの未検出"
type temp.log | findstr "**** Step" >> test.log
type test.log | find "***No errors"
goto END

:::::::::::ログファイルを削除:::::::::::::
:CLEANLOG
del test.log 2>nul
del temp.log 2>nul
goto END

:CLEAN
if exist mvc.log rmdir  mvc.log /s /q
if exist test.bat call test.bat clean
if exist testx.bat call testx.bat clean

:END
if "%TEMP_LOG%"=="" del temp.log 2>nul
cd %BAT_DIR%

