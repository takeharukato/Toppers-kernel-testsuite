::/* TOPPERSカーネルテストスイート
:: * 
:: *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
:: * 
:: *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation
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
:: *
:: *  @(#) $Id: test.bat,v 1.0 2004/04/22 00:00:00 morita Exp $
:: */

SET TEST_CASE=com
SET BLD_FILE=05
SET GRUN_TEST=0

SET  NO_ERROR=0
SET  BLD_ERROR=0

::::コンフィギュレーションファイルをプリプロセッサに通す::::
call %TEST_DIR%test_case.bat %1
if not "%1" == "" goto END
if errorlevel 1 goto LE

:::プリプロセッサの結果をカーネルコンフィギュレータに通す:::
call %TEST_DIR%configure.bat test1.i
call %TEST_DIR%configure.bat test2.i
call %TEST_DIR%configure.bat test3.i
call %TEST_DIR%configure.bat test4.i
echo ---Reached Last Step---
IF %BLD_ERROR% == 0 GOTO L1
:LE
echo ***Build failed*** >> test.log
SET ERRORLEVEL=2
goto END

:L1
SET ERRORLEVEL=%NO_ERROR%
goto END

:::::::::::::処理中にエラーが発生:::::::::::::::::::::::::::
:ERROR
SET BLD_ERROR=1

:::::::::::::::一時ファイルを削除し終了:::::::::::::::::::::::
:END
del s*.i 2>nul
del kernel_cfg.c 2>nul
del kernel_id.h  2>nul
SET TEST_CASE=
SET BLD_FILE=
SET GRUN_TEST=
SET NO_ERROR=
SET BLD_ERROR=
