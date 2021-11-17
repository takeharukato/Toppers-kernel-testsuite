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
IF "%1"=="help" goto %1
IF NOT exist %CFG%\cfg.exe GOTO N1
IF NOT exist library\libkernel.a GOTO N2
GOTO N3

:N1
echo "cfg.exeがありません。作成してください。”
echo .
GOTO END

:N2
echo "libkernel.aがありません。作成してください。”
echo .
GOTO END

:N3
SET BAT_DIR=%DRIVE_T%\std_test\
%BAT_DIR%auto_test.bat %1 %2 %3 %4
GOTO END

:help
echo "auto_test [. [<log_file>]]          全テスト一括実行"
echo "auto_test <test_case> [<log_file>]  指定テストケースのみ実行"
echo "          01com                     01com にある01 から 全てを実行”
echo            01com\01                  01com にある01 だけを実行”
echo "auto_test . clean                   中間ファイルの削除"
echo "auto_test . cleanlog                ログファイルの削除"
echo "auto_test . dumplog <log_file>      テスト結果の結合"
echo.

:END

