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

#define _TEST_TIME 2
#define _LAST_STEP 52
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CFLG k_cflg1 = { TA_TFIFO|TA_WMUL    , IFLGPTN_0 } ;
T_CFLG k_cflg2 = { TA_TPRI|TA_WMUL    , IFLGPTN_0 } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 18 ) ;
		ercd = wai_flg( FLG_ID1, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 29 ) ;
		_CHECK_ASSERT_E_DLT( ercd ) ;
									_CHECK_STEP( 30 ) ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 38 ) ;
		ercd = wai_flg( FLG_ID1, WAIPTN_AAAA, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 47 ) ;
		_CHECK_ASSERT_E_DLT( ercd ) ;
									_CHECK_STEP( 48 ) ;
	}
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 15 ) ;
		ercd = wai_flg( FLG_ID1, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 27 ) ;
		_CHECK_ASSERT_E_DLT( ercd ) ;
									_CHECK_STEP( 28 ) ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 35 ) ;
		ercd = wai_flg( FLG_ID1, WAIPTN_AAAA, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 49 ) ;
		_CHECK_ASSERT_E_DLT( ercd ) ;
									_CHECK_STEP( 50 ) ;
	}
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = ref_flg( ERR_FLG_ID, &k_rflg ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rflg = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_flg( FLG_ID2, pk_rflg ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_flg( FLG_ID1, &k_rflg ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_flg( FLG_ID2, &k_rflg ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( k_rflg.wtskid == TSK_NONE ) ;
_PRINT_VER( k_rflg.wtskid) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( k_rflg.flgptn == SETPTN_0505 ) ;
_PRINT_VER( k_rflg.flgptn )
									_CHECK_STEP( 12 ) ;
	ercd = cre_flg( FLG_ID1, &k_cflg1 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 14 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 20 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_AAAA ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 22 ) ;
	ercd = ref_flg( FLG_ID1, &k_rflg ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( k_rflg.wtskid == TASK_ID2 ) ;
_PRINT_VER( k_rflg.wtskid) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT( k_rflg.flgptn == SETPTN_AAAA ) ;
_PRINT_VER( k_rflg.flgptn) ;
									_CHECK_STEP( 26 ) ;
	ercd = del_flg( FLG_ID1 ) ;

									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	ercd = cre_flg( FLG_ID1, &k_cflg2 ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_5555 ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ercd = ref_flg( FLG_ID1, &k_rflg ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT( k_rflg.wtskid == TASK_ID1) ;
_PRINT_VER( k_rflg.wtskid) ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT( k_rflg.flgptn == SETPTN_5555 ) ;
_PRINT_VER( k_rflg.flgptn) ;
									_CHECK_STEP( 46 ) ;
	ercd = del_flg( FLG_ID1 ) ;

									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ext_tsk() ;
}

