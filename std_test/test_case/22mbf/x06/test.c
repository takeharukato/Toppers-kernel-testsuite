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
#define _LAST_STEP 40
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB snd_buf[MBFSZ_256];
VB rcv_buf[MBFSZ_256];
VB msg_buf1[MBFSZ_4K];

T_CMBF k_cmbf1 = { TA_TFIFO,    MAXMSZ, MBFSZ_256,  msg_buf1 } ;


void TASK1(VP_INT exinf)
{
	ER_UINT ercd ;
									_CHECK_STEP( 17 ) ;
	ercd = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MAXMSZ ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MAXMSZ ) ;

									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	VP blk ;
									_CHECK_STEP( 1 ) ;
	ercd = ref_mbf( ERR_MBF_ID, &k_rmbf ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rmbf = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_mbf( MBF_ID2, pk_rmbf ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_mbf( MBF_ID1, &k_rmbf ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_mbf( MBF_ID2, &k_rmbf ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( k_rmbf.stskid == TSK_NONE ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( k_rmbf.rtskid == TSK_NONE ) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT( k_rmbf.smsgcnt == 0 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT( k_rmbf.fmbfsz > MAXMSZ ) ;
_PRINT_VER( k_rmbf.fmbfsz) ;
									_CHECK_STEP( 14 ) ;
	ercd = cre_mbf( MBF_ID1, &k_cmbf1 ) ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 16 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 19 ) ;
	ercd = ref_mbf( MBF_ID1, &k_rmbf ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( k_rmbf.stskid == TSK_NONE ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( k_rmbf.rtskid == TASK_ID1 ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( k_rmbf.smsgcnt == 0 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( k_rmbf.fmbfsz > MAXMSZ ) ;
_PRINT_VER( k_rmbf.fmbfsz) ;
									_CHECK_STEP( 25 ) ;
	ercd = rel_wai( TASK_ID1 ) ;

									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = ref_mbf( MBF_ID2, &k_rmbf ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( k_rmbf.stskid == TASK_ID1 ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( k_rmbf.rtskid == TSK_NONE ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT( k_rmbf.smsgcnt == 1 ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( k_rmbf.fmbfsz < MAXMSZ ) ;
_PRINT_VER( k_rmbf.fmbfsz) ;
									_CHECK_STEP( 37 ) ;
	ercd = rel_wai( TASK_ID1 ) ;

									_CHECK_STEP( 40 ) ;
	ext_tsk() ;
}

