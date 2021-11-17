/* TOPPERSカーネルテストスイート
 * 
 *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
 * 
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 *
 *  @(#) $Id: test.c,v 1.0 2004/04/22 00:00:00 morita Exp $
 */

#include <kernel.h>
#include "test.h"
#include "kernel_id.h"

#define _TEST_TIME 3
#define _LAST_STEP 105
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CFLG k_cflg1 = { TA_TFIFO, IFLGPTN_1 } ;
T_CFLG k_cflg2 = { TA_TPRI , IFLGPTN_0 } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 79 ) ;
	ercd = wai_flg( FLG_ID6, WAIPTN_0055, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 84 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 90 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 91 ) ;
	ercd = wai_flg( FLG_ID7, WAIPTN_0505, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 101 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 102 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0505 ) ;
									_CHECK_STEP( 103 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 40 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ercd = wai_flg( FLG_ID2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 54 ) ;
	ercd = wai_flg( FLG_ID3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 56 ) ;
	ercd = wai_flg( FLG_ID4, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 68 ) ;
	ercd = wai_flg( FLG_ID5, WAIPTN_8000, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 74 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_8000 ) ;
									_CHECK_STEP( 76 ) ;
	ercd = wai_flg( FLG_ID6, WAIPTN_0055, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 85 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 86 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 87 ) ;
	ercd = wai_flg( FLG_ID7, WAIPTN_0005, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 94 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 95 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0005 ) ;
									_CHECK_STEP( 96 ) ;
	ercd = set_flg( FLG_ID7, SETPTN_0500 ) ;
									_CHECK_STEP( 97 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 98 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 34 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 37 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_0002 ) ;
									_CHECK_STEP( 47 ) ;
	ercd = wai_flg( FLG_ID2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 49 ) ;
	ercd = wai_flg( FLG_ID3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 59 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_0002 ) ;
									_CHECK_STEP( 61 ) ;
	ercd = wai_flg( FLG_ID4, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 63 ) ;
	ercd = wai_flg( FLG_ID5, WAIPTN_8000, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_8000 ) ;
									_CHECK_STEP( 73 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = cre_flg( ERR_FLG_ID, &k_cflg1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_cflg = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = cre_flg( E_FLG_ID1, pk_cflg ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = ERR_FLGATR ;
									_CHECK_STEP( 7 ) ;
	ercd = cre_flg( E_FLG_ID2, &k_cflg ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 9 ) ;
#ifdef ERR_IFLGPTN
	k_cflg = k_cflg1 ;
	k_cflg.iflgptn = ERR_IFLGPTN ;
									_CHECK_STEP( 10 ) ;
	ercd = cre_flg( E_FLG_ID3, &k_cflg ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 10 ) ;
									_CHECK_STEP( 11 ) ;
#endif
									_CHECK_STEP( 12 ) ;
	ercd = cre_flg( FLG_ID1, &k_cflg1 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 14 ) ;
	ercd = cre_flg( FLG_ID1, &k_cflg1 ) ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 16 ) ;
	ercd = cre_flg( FLG_ID2, &k_cflg2 ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WSGL ;
									_CHECK_STEP( 19 ) ;
	ercd = cre_flg( FLG_ID3, &k_cflg ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	k_cflg = k_cflg2 ;
	k_cflg.flgatr = TA_TPRI|TA_WSGL ;
									_CHECK_STEP( 22 ) ;
	ercd = cre_flg( FLG_ID4, &k_cflg ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WMUL ;
									_CHECK_STEP( 25 ) ;
	ercd = cre_flg( FLG_ID5, &k_cflg ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;
	k_cflg = k_cflg2 ;
	k_cflg.flgatr = TA_TPRI|TA_WMUL ;
									_CHECK_STEP( 28 ) ;
	ercd = cre_flg( FLG_ID6, &k_cflg ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WMUL|TA_CLR ;
									_CHECK_STEP( 31 ) ;
	ercd = cre_flg( FLG_ID7, &k_cflg ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	ercd = act_tsk( TASK_ID4 ) ;

									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_0002 ) ;

									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = set_flg( FLG_ID2, SETPTN_0001 ) ;

									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 58 ) ;
	ercd = set_flg( FLG_ID3, SETPTN_0002 ) ;

									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	ercd = set_flg( FLG_ID4, SETPTN_0001 ) ;

									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 70 ) ;
	ercd = set_flg( FLG_ID5, SETPTN_8000 ) ;

									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 78 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 81 ) ;
	ercd = set_flg( FLG_ID6, SETPTN_0001 ) ;

									_CHECK_STEP( 88 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 89 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 92 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 93 ) ;
	ercd = set_flg( FLG_ID7, SETPTN_0005 ) ;

									_CHECK_STEP( 99 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 100 ) ;
	ercd = set_flg( FLG_ID7, SETPTN_0005 ) ;

									_CHECK_STEP( 104 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 105 ) ;
	ext_tsk() ;
}

