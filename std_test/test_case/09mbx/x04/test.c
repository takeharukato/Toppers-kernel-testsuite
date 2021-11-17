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
#define _LAST_STEP 70
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CMBX k_cmbx1 = { TA_TFIFO|TA_MFIFO, 0, NULL } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 18 ) ;
	ercd = rcv_mbx( MBX_ID2, ppk_msg ) ;

									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 30 ) ;
	ercd = rcv_mbx( MBX_ID1, ppk_msg ) ;

									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 45 ) ;
	msg1.msgpri = TSKPRI_1 ;
									_CHECK_STEP( 46 ) ;
	ercd = snd_mbx( MBX_ID2, &msg1 ) ;
									_CHECK_STEP( 47 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 48 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 62 ) ;
	ercd = snd_mbx( MBX_ID1, &msg1 ) ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 64 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 15 ) ;
	ercd = rcv_mbx( MBX_ID2, ppk_msg ) ;

									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 26 ) ;
	ercd = rcv_mbx( MBX_ID1, ppk_msg ) ;

									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 38 ) ;
	msg2.msgpri = TSKPRI_2 ;
									_CHECK_STEP( 39 ) ;
	ercd = snd_mbx( MBX_ID2, &msg2 ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 41 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 56 ) ;
	ercd = snd_mbx( MBX_ID1, &msg2 ) ;
									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 58 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = ref_mbx( ERR_MBX_ID, &k_rmbx ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rmbx = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_mbx( MBX_ID2, pk_rmbx ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_mbx( MBX_ID1, &k_rmbx ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_mbx( MBX_ID2, &k_rmbx ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( k_rmbx.wtskid == TSK_NONE ) ;
_PRINT_VER( k_rmbx.wtskid) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( k_rmbx.pk_msg == NULL ) ;
									_CHECK_STEP( 12 ) ;
	ercd = cre_mbx( MBX_ID1, &k_cmbx1 ) ;
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
	ercd = ref_mbx( MBX_ID2, &k_rmbx ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( k_rmbx.wtskid == TASK_ID1 ) ;
_PRINT_VER( k_rmbx.wtskid) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( k_rmbx.pk_msg == NULL ) ;
									_CHECK_STEP( 24 ) ;
	ercd = rel_wai( TASK_ID2 ) ;

									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	ercd = rel_wai( TASK_ID1 ) ;

									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	ercd = ref_mbx( MBX_ID1, &k_rmbx ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( k_rmbx.wtskid == TASK_ID2 ) ;
_PRINT_VER( k_rmbx.wtskid) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT( k_rmbx.pk_msg == NULL ) ;
									_CHECK_STEP( 36 ) ;
	ercd = rel_wai( TASK_ID2 ) ;

									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 43 ) ;
	ercd = rel_wai( TASK_ID1 ) ;

									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 50 ) ;
	ercd = ref_mbx( MBX_ID2, &k_rmbx ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT( k_rmbx.wtskid == TSK_NONE ) ;
_PRINT_VER( k_rmbx.wtskid) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT( k_rmbx.pk_msg == &msg1 ) ;
_PRINT_VER( k_rmbx.pk_msg ) ;
									_CHECK_STEP( 54 ) ;
	ercd = wup_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 59 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 60 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 66 ) ;
	ercd = ref_mbx( MBX_ID1, &k_rmbx ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT( k_rmbx.wtskid == TSK_NONE ) ;
_PRINT_VER( k_rmbx.wtskid) ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT( k_rmbx.pk_msg == &msg2 ) ;
_PRINT_VER( k_rmbx.pk_msg ) ;
									_CHECK_STEP( 70 ) ;
	ext_tsk() ;
}

